// Header  {{{
#include<iostream>
#include<vector>
#include<climits>
#define Min(x, y) x > y ? y : x
using namespace std;
// }}}
// functions {{{
void initialization(unsigned long long sum_of_weight[2001], unsigned long long weight[2001], unsigned long long energy[21][2001], int N, int K)
{
	sum_of_weight[0] = weight[0];
	for(int i = 1; i < N; i++)
	{
		sum_of_weight[i] = sum_of_weight[i - 1] + weight[i];
		cout << sum_of_weight[i] << "\n";
	}
	energy[1][0] = 0;
	for(int i = 1; i < N; i++)
	{
		energy[1][i] = energy[1][i - 1] + weight[i];
		cout << energy[1][i] << "\n";
	}
}
unsigned long long DP(unsigned long long energy[21][2001], unsigned long long sum_of_weight[2001], unsigned long long weight[2001], int K, int N)
{
	if(energy[K][N] > 0)return energy[K][N];
	if(K >= N) return 0;
	unsigned long long temp = ULLONG_MAX;
	for(int i = 0; i < N; i++)
		temp = Min(temp, (DP(energy, sum_of_weight, weight, K - 1, i) + (energy[1][N] - energy[1][i] - (unsigned long long)(N - i) * sum_of_weight[i])));
	energy[K][N] = temp;
	return energy[K][N];
}
// }}}
// int main()  {{{
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long sum_of_weight[2001], energy[21][2001] = {{0}}, weight[2001];
	//bool energy_existed[24][100016] = {{}};
	int N, K, temp;
	cin >> N >> K;
	for(int i = 0 ; i < N; i++)
		cin >> weight[i];
	initialization(sum_of_weight, weight, energy, N, K);
	cout << DP(energy, sum_of_weight, weight, K, N);
	return 0;
}
//}}}

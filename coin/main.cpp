//< Header >{{{
#include<iostream>
using namespace std;
#define MOD 1000000007
//}}}
//< Globle Variables >{{{
unsigned long long SUM, N, coin[100], Count[100][10001];
bool counted[100][10001] = {0};
//}}}
//< unsigned long long coin_count() >{{{
unsigned long long coin_count(int n, int sum)
{
	if(n < 0 || sum < 0)return 0;
	if(sum == 0)return 1;
	if(counted[n][sum]) return Count[n][sum];
	Count[n][sum] = (coin_count(n - 1, sum) + coin_count(n, sum - coin[n])) % MOD;
	counted[n][sum] = true;
	return Count[n][sum];
}
//}}}
//< int main() >{{{
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> SUM;
	for(int i = 0; i < N; i++)
		cin >> coin[i];
	cout << coin_count(N - 1, SUM);
}
//}}}

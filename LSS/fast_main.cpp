#include<iostream>
#include<vector>
using namespace std;
vector<int>lcsA, lcsB;
int A[2001], B[2001], dp[2001][2001] = {0};
int lls(int N, int M, int K)
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
		{
			if(A[i] == B[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				lcsA.push_back(i);
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	if(K == 0)return dp[N][M];
	else
	{
		if(K >= N && K >= M)
			return (N > M) ? M : N;
		else if(K >= N) return N;
		else if(K >= M) return M;
		else
		{
			for(int i = 1, idx = 0; i <= M; i++)
				if(B[i] == lcsA[idx])
				{
					lcsB.push_back(i);
					idx++;
				}
			int sum = 0;
			for(int i = 0; i < lcsA.size() - 1; i++)
				sum += min(lcsB[i + 1] - lcsB[i], lcsA[i + 1] - lcsA[i]);
			return min(((K > sum) ? K : sum) + (int)lcsA.size(), (M > N) ? N : M);
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++)
		cin >> A[i];
	for(int i = 1; i <= M; i++)
		cin >> B[i];
	cout << lls(N, M, K);
	return 0;
}

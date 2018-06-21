#include<iostream>
using namespace std;
int A[2001], B[2001], dp[21][2001][2001];
int lss(int N, int M, int K)
{
	int k, m, n;
	for(k = 0; k <= K; k++)
	{
		for(n = 1; n <= N; n++)
		{
			for(m = 1; m <= M; m++)
			{
				if(A[n] == B[m])
					dp[k][n][m] = dp[k][n - 1][m - 1] + 1;
				else
					dp[k][n][m] = max(max(dp[k][n][m - 1], dp[k][n - 1][m]), (k == 0) ? 0 : dp[k - 1][n - 1][m - 1] + 1);
				if(dp[k][n][M] == M) return M;
			}
		}
		if(dp[k][N][M] == N) return N;
	}
	return dp[K][N][M];
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
	cout << lss(N, M, K);
	return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct MAX_CLIQUE 
{
	static const int N = 200;
	bool G[N][N];
	int n, Max[N], Alt[N][N], ans;
	bool DFS(int cur, int tot) 
	{
		if(cur == 0) 
		{
			if(tot > ans) 
			{
				ans = tot;
				return 1;
			}
			return 0;
		}
		for(int i = 0; i < cur; i++) 
		{
			if(cur - i + tot <= ans) return 0;
			int u = Alt[tot][i];
			if(Max[u] + tot <= ans) return 0;
			int nxt = 0;
			for(int j = i + 1; j < cur; j++)
				if(G[u][Alt[tot][j]]) Alt[tot + 1][nxt++] = Alt[tot][j];
			if(DFS(nxt, tot + 1)) return 1;
		}
		return 0;
	}
	int MaxClique() 
	{
		ans = 0, memset(Max, 0, sizeof Max);
		for(int i = n - 1; i >= 0; i--) 
		{
			int cur = 0;
			for(int j = i + 1; j < n; j++) if(G[i][j]) Alt[1][cur++] = j;
			DFS(cur, 1);
			Max[i] = ans;
		}
		return ans;
	}
};
MAX_CLIQUE fuc;
int main() 
{
	int M, i, j;
	scanf("%d%d", &fuc.n, &M);
	for(i = 0; i < fuc.n; i++)
		for(j = 0; j < fuc.n; j++)
			fuc.G[i][j] = false;
	while(M--)
	{
		scanf("%d%d", &i, &j);
		fuc.G[i][j] = true;
		fuc.G[j][i] = true;
	}
	printf("%d\n", fuc.MaxClique());
	return 0;
}

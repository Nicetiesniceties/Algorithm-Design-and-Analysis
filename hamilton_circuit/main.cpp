#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	vector< unordered_map < int, int > > AdjacencyList(N + 1);
	vector< unordered_map < int, int > > reverseAdjacencyList(N + 1);
	int to[N], from[N], degree[N] = {}, v1, v2;
	while(M--)
	{
		cin >> v1 >> v2;
		if(AdjacencyList[v1].find(v2))
		indegree[v1]++, outdegree[v2]++;
		AdjacencyList[v1].insert(make_pair(v2, 1));
		reverseAdjacencyList[v2].insert(make_pair(v1, 1));
	}
	for(int i = 0; i < N; i++)
	{
		if(degree[i] == 1)
		{
			to[i] = AdjacencyList[i].begin()->first;
			from[i] = reverseAdjacencyList[i].begin()->second;
		}
	}
	return 0;
}

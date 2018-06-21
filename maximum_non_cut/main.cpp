#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<utility>
#include<queue>
#include<climits>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	vector< list< pair< long long int, long long int > > > adjacencyList(n + 1);
	vector< long long int > MIN_WEIGHT_SUM(n + 1);
	priority_queue< pair< long long int, long long int >, vector< pair< long long int, long long int > >, greater< pair< long long int, long long int > > > pq;
	for(int i = 1; i <= n; i++)
		MIN_WEIGHT_SUM[i] = -1;
	long long int v1, v2, weight, all = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> weight;
		all += weight;
		adjacencyList[v1].push_back(make_pair(v2, weight));
		adjacencyList[v2].push_back(make_pair(v1, weight));
	}
	pq.push(make_pair(0, s));
	MIN_WEIGHT_SUM[s] = 0;
	while(!pq.empty())
	{
		pair<long long int, long long int> start = pq.top();
		pq.pop();
		long long int top_id = start.second;
			MIN_WEIGHT_SUM[top_id] = start.first;
		if(top_id == t) break;
		while(!adjacencyList[top_id].empty())
		{
			long long int target_weight = adjacencyList[top_id].front().second, target_id = adjacencyList[top_id].front().first;
			if(MIN_WEIGHT_SUM[target_id] != -1)
			{
				adjacencyList[top_id].pop_front();
				continue;
			}
			pq.push(make_pair(target_weight + MIN_WEIGHT_SUM[top_id], target_id));
			adjacencyList[top_id].pop_front();
		}
	}
	if(MIN_WEIGHT_SUM[t] != -1)cout << all - MIN_WEIGHT_SUM[t];
	else cout << -1 << '\n';
	return 0;
}

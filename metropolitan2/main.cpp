#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector< int > degree, degree_order;
bool degreecmp(int i, int j)
{
	return degree[i] < degree[j];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, ans = 1, v1, v2;
	cin >> N >> M;
	vector< unordered_map < int, int > > AdjacencyList(N + 1);
	for(int i = 0; i < N; i++)
		degree.push_back(0), degree_order.push_back(i);
	while(M--)
	{
		cin >> v1 >> v2;
		degree[v1]++, degree[v2]++;
		AdjacencyList[v1].insert(make_pair(v2, 1));
		AdjacencyList[v2].insert(make_pair(v1, 1));
	}
	sort(degree_order.begin(), degree_order.end(), degreecmp);
	for(int i = 0; i < N; i++)
		cout << "degree_order: " << degree_order[i] << " degree: " << degree[degree_order[i]] << '\n';
	cout << "-----\n";
	for(int i = 0; i < N; i++)
	{
		//cout << i << '\n';
		int deg = degree[degree_order[i]], idx = degree_order[i];
		cout << "idx: " << idx << " deg: " << deg << '\n';
		if(deg + 1 < ans) continue;
		else
		{
			//some debug-friendly preparation
			int j = 0, neighbor_index[deg], is_complete = 1;
			for(unordered_map< int, int >::iterator it = AdjacencyList[degree_order[i]].begin(); j < deg; ++it, j++)
				neighbor_index[j] = it->first;
			//determine whether the neighbors are connected
			for(int r = 0; r < deg; r++)
				for(j = 0; j < deg; j++)
				{
					if(r == j) continue;
					else if(AdjacencyList[neighbor_index[r]].find(neighbor_index[j]) == AdjacencyList[neighbor_index[r]].end())
					{
						is_complete = 0;
						break;
					}
				}
			if(is_complete == 1)ans = deg + 1;
			//remove idx from the graph
			degree[idx]--;
			for(j = 0; j < deg; j++)
			{
				degree[neighbor_index[j]]--;
				AdjacencyList[neighbor_index[j]].erase(AdjacencyList[neighbor_index[j]].find(idx));
			}
			sort(degree_order.begin(), degree_order.end(), degreecmp);
		}
	}
	cout << "-----\n";
	cout << ans;
	return 0;
}

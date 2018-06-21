#include<iostream>
#include<vector>
#include<unordered_map>
#define SIZE 10005
using namespace std;
int types[SIZE], sum = 0, type_num[4], N, M, num = 0, mum = 0;
unordered_map< int, int > q(SIZE);
int reverse(int type)
{
	if(type == 1)
		return 2;
	return 1;
}
void delete_remain(int idx,  vector< vector< int > > AdjacencyList)
{
	if(q.find(idx) != q.end()) 
	{
		q.erase(q.find(idx));
		num++;
		for(int i = 0; i < AdjacencyList[idx].size(); i++)
			delete_remain(AdjacencyList[idx][i], AdjacencyList);
	}
}
bool determine(int idx, int type, vector< vector< int > > AdjacencyList)
{
	types[idx] = type;
	for(int i = 0; i < AdjacencyList[idx].size(); i++)
	{
		if(types[AdjacencyList[idx][i]] == 0)
		{
			if(determine(AdjacencyList[idx][i], reverse(types[idx]), AdjacencyList) == false)
				return false;
		}
		else if(types[AdjacencyList[idx][i]] == types[idx])
			return false;
	}
	type_num[type]++;
	return true;
}
void bipartite(vector< vector< int > > AdjacencyList, int index)
{
	for(int i = 1; i <= N; i++)
		types[i] = 0;
	type_num[0] = type_num[1] = type_num[2] = 0;
	if(types[index] == 0)
		if(determine(index, 1, AdjacencyList) == false)
		{
			num = mum = 0;
			delete_remain(index, AdjacencyList);
			sum += num * (num + 1) / 2 - num + 1;
			return;
		}
	num = mum = 0;
	delete_remain(index, AdjacencyList);
	sum += type_num[1] * type_num[2] - num;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, v1, v2;
	cin >> T;
	while(T--)
	{
		vector< vector< int > > AdjacencyList(SIZE);
		sum = 0;
		cin >> N >> M;
		for(int i = 1; i < N; i++)
			q.insert(make_pair(i, i));
		for(int i = 0; i < M; i++)
		{
			cin >> v1 >> v2;
			AdjacencyList[v1].push_back(v2);
			AdjacencyList[v2].push_back(v1);
		}
		while(!q.empty())
		{
			bipartite(AdjacencyList, q.begin()->first);
		}
		cout << sum << '\n';
		AdjacencyList.clear();
	}
	return 0;
}

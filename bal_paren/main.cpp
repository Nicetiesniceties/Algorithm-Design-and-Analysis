#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define ull unsigned long long
using namespace std;
int main()
{
	char String[1000024];
	int l[1000024], r[1000024], value= 0, Count = 0;
	ull cost;
	vector<int> heap;
	scanf("%s", String);
	//make_heap(heap.begin(), heap.end());
	while(scanf("%d%d", &l[Count], &r[Count]) != EOF)
		Count++;
	Count = 0;
	for(int i = 0; i < strlen(String); i++)
	{
		if(String[i] == '(')
			value++;
		else if(String[i] == ')')
		{
			value--;
			if(value < 0)
			{
				if(heap.size() == 0)
				{
					printf("Impossible");
					return 0;
				}
				else
				{
					value += 2;
					cost -= heap.front();
					pop_heap (heap.begin(), heap.end());
					heap.pop_back();
				}
			}
		}
		else if(String[i] == '?')
		{
			value--;
			heap.push_back(r[Count]  - l[Count]);
			push_heap(heap.begin(), heap.end());
			cost += r[Count];
			if(value >= 0)
			{
				Count++;
				continue;
			}
			else if(value < 0)
			{
				if(heap.size() == 0)
				{
					printf("Impossible");
					return 0;
				}
				else
				{
					cost -= heap.front();
					pop_heap (heap.begin(), heap.end());
					heap.pop_back();
					value += 2;
				}
			}
			Count++;
		}
	}
	if(value != 0) printf("Impossible");
	else printf("%llu", cost);
	return 0;
}

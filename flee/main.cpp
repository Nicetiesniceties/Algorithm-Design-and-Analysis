#include<iostream>
#include<climits> 
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;
int R, C, step[3002][3002], num_of_P = 0;
char status[3002][3002];
queue<int> bfs_queue_x, bfs_queue_y, people_queue_x, people_queue_y;
int dir_x[4] = {1, 0, -1, 0}, dir_y[4] = {0, 1, 0, -1};
//void read_input(void){{{
void read_input(void)
{
	cin >> R >> C;
	char c;
	memset(status, 'F', sizeof(status));
	memset(step, 0, sizeof(step));
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
		{
			cin >> status[i][j];
			if(status[i][j] == 'P')
			{
				num_of_P++;
				people_queue_x.push(i);
				people_queue_y.push(j);
			}
			else if(status[i][j] == 'E')
			{
				step[i][j] = 0;
				bfs_queue_x.push(i);
				bfs_queue_y.push(j);
			}
		}
}
//}}}
//void bfs(void){{{
void bfs(void)
{
	while(!bfs_queue_x.empty())
	{
		for(int i = 0; i < 4; i++)
		{
			if(step[bfs_queue_x.front() + dir_x[i]][bfs_queue_y.front() + dir_y[i]] != 0)
				continue;
			else if(status[bfs_queue_x.front() + dir_x[i]][bfs_queue_y.front() + dir_y[i]] == 'P')
			{
				step[bfs_queue_x.front() + dir_x[i]][bfs_queue_y.front() + dir_y[i]] = 
				  step[bfs_queue_x.front()][bfs_queue_y.front()] + 1;
				num_of_P--;
				if(num_of_P == 0)return;
				bfs_queue_x.push(bfs_queue_x.front() + dir_x[i]);
				bfs_queue_y.push(bfs_queue_y.front() + dir_y[i]);
			}
			else if(status[bfs_queue_x.front() + dir_x[i]][bfs_queue_y.front() + dir_y[i]] == '.')
			{
				step[bfs_queue_x.front() + dir_x[i]][bfs_queue_y.front() + dir_y[i]] = 
				  step[bfs_queue_x.front()][bfs_queue_y.front()] + 1;
				bfs_queue_x.push(bfs_queue_x.front() + dir_x[i]);
				bfs_queue_y.push(bfs_queue_y.front() + dir_y[i]);
			}
		}
		bfs_queue_x.pop();
		bfs_queue_y.pop();
	}
}
//}}}
// void print_output(void){{{
void print_output(void)
{
	while(!people_queue_y.empty())
	{
		if(step[people_queue_x.front()][people_queue_y.front()] != 0)
			cout << step[people_queue_x.front()][people_queue_y.front()] << '\n';
		else
			cout << "Died\n";
		people_queue_x.pop();
		people_queue_y.pop();
	}
}
//}}}
//{{{int main()
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	read_input();
	bfs();
	print_output();
	return 0;
}
//}}}

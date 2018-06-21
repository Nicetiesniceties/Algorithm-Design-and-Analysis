#include<iostream>
using namespace std;
void hanoi(unsigned long long n, int begin, int buffer, int aim);
unsigned long long step = 1, l, r, n;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int testcase;
	cin >> testcase;
	for(int i = 1; i <= testcase; i++)
	{
		cin >> n >> l >> r;
		cout << "Case #" << i << ":\n";
		hanoi(n, 1, 2, 3);
		step = 1;
	}
	return 0;
}
void hanoi(unsigned long long n, int begin, int buffer, int aim)
{
	if(n == 1)
	{
		cout << "Step " << step++ << ": #" << begin << " -> #" << aim << "\n";
		return;
	}
	hanoi(n - 1, begin, aim , buffer);
	cout << "Step " << step++ << ": " << "#" << begin << " -> #" << aim << "\n";
	hanoi(n - 1, buffer, begin, aim);
	return;
}

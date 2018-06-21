#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long a, b, n, temp, testcase;
	cin >> testcase;
	while(testcase--)
	{
		cin >> a >> b >> n;
		if(n <= 2)
		{
			if(n == 1)cout << a << "\n";
			if(n == 2)cout << b << "\n";
		}
		else
		{
			for(int i = 3; i <= n; i++)
			{
				temp = b;
				b = (a + b) % 1000000007;
				a = temp;
			}
			cout << b << "\n";	
		}
	}
	return 0;
}

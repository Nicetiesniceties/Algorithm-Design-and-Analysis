#include<iostream>
#include<vector>
#define ull unsigned long long
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testcase, i, Count;
	ull s[100], sum, n;
	vector<ull> ans;
	cin >> testcase;
	while(testcase--)
	{
		bool impossible = false;
		cin >> n >> sum;
		for(i = 0 ; i < n; i++)
			cin >> s[i];
		Count = i - 1;
		while(sum > 0 && Count >= 0)
		{
			if(sum < s[Count])
			{
				Count--;
				continue;
			}
			else if(sum >= s[Count])
			{
				//cout << s[Count];
				ans.push_back(s[Count]);
				sum -= s[Count--];
			}
			else if(sum / 2 >= s[Count])
			{
				impossible = true;
				break;
			}
		}
		if((sum != 0) || impossible == true)
			cout << "-1\n";
		else
		{
			cout << ans.size() << '\n';
			for(i = ans.size() - 1; i >= 0; i--)
				cout << ans[i] << (i == 0 ? '\n' : ' ');
		}
		ans.clear();
	}
	return 0;
}

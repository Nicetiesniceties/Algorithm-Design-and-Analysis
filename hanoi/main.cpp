// Header {{{
#include<iostream>
#include<climits>
using namespace std;
unsigned long long l, r;
int n;
//}}}
// void hanoi(int n, int begin, int buffer, int aim, __int128 step) {{{
void hanoi(int n, int begin, int buffer, int aim, __int128 step)
{
	//marginal condition 
	if(n == 0)return;
	if(l > r)return;
	if(step > l)
		hanoi(n - 1, begin, aim, buffer, step - ((__int128)1 << (n - 2)));
	if(step == l)
	{
		if(l <= r)cout << "Step " << l++ << ": " << "#" << begin << " -> #" << aim << "\n";
	}
	if(step < l)
		hanoi(n - 1, buffer, begin, aim, step + ((__int128)1 << (n - 2)));
	return;
}
//}}}
// int main() {{{
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
		hanoi(n, 1, 2, 3, ((__int128)1 << (n - 1)));
	}
	return 0;
}
// }}}

#include<iostream>
using namespace std;
void func(int a[2][2])
{
	a[0][0] = a[1][0] = a[0][1] = a[1][1] = 2;
	return ;
}
int main()
{
	int a[2][2] = {0};
	func(a);
	cout << a[0][0] << a[1][0] << a[0][1] << a[1][1];
	return 0;
}

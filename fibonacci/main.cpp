// header {{{
#include<iostream>
#define MOD 1000000007
using namespace std;
unsigned long long hanhan(unsigned long long a, unsigned long long b, unsigned long long n);
unsigned long long exponentiation(unsigned long long a, unsigned long long b, unsigned long long n); 
void multiply(unsigned long long base[2][2], unsigned long long result[2][2]);
}}} // 
// int main() {{{
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long testcase, a, b, n;
	cin >> testcase;
	while(testcase--)
	{
		cin >> a >> b >> n;
		cout << hanhan(a, b, n) << "\n";
	}
	return 0;
}
}}}//
// unsigned long long hanhan() {{{
unsigned long long hanhan(unsigned long long a, unsigned long long b, unsigned long long n)
{
	if(n <= 2)
	{
		if(n == 1)return a;
		else if(n == 2)return b;
	}
	return exponentiation(a, b, n - 2);
}
//}}}
// unsigned long long exponentiation() {{{
unsigned long long exponentiation(unsigned long long a, unsigned long long b, unsigned long long n) 
{
	// |1 1| |a+b b| __ |a+2b a+b|   |base[0][0] base[1][0]|
	// |1 0| | b  a| –– |a+b   b |   |base[0][1] base[1][1]|
	unsigned long long base[2][2] = {{1, 1}, {1, 0}}, result[2][2] = {{(a + b) % MOD, b}, {b, a}};
	while(n > 0) 
	{
		if(n % 2 == 1)
			multiply(base, result);
		multiply(base, base);
		n /= 2;
		//cout << "result:\n";
		//cout << "|" << result[0][0] << " " << result[1][0] << "|\n";
		//cout << "|" << result[0][1] << " " << result[1][1] << "|\n";
		//cout << "base:\n";
		//cout << "|" << base[0][0] << " " << base[1][0] << "|\n";
		//cout << "|" << base[0][1] << " " << base[1][1] << "|\n";
	}
	return result[1][0];
}
//}}} 
// void multiply() {{{
void multiply(unsigned long long base[2][2], unsigned long long result[2][2])
{
	unsigned long long m1 = (base[0][0] * result[0][0] + base[1][0] * result[0][1]) % MOD;
	unsigned long long m2 = (base[0][0] * result[1][0] + base[1][0] * result[1][1]) % MOD;
	unsigned long long n1 = (base[0][1] * result[0][0] + base[1][1] * result[0][1]) % MOD;
	unsigned long long n2 = (base[0][1] * result[1][0] + base[1][1] * result[1][1]) % MOD;
	result[0][0] = m1 % MOD;
	result[1][0] = m2 % MOD;
	result[0][1] = n1 % MOD;
	result[1][1] = n2 % MOD;
}
//}}}

// Author: Akshay A Baiju
// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: recursive - memoization
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll 		long long
#define vll 	vector <ll>
const int M = 1e9+7;

vll dp(1e6+7,-1);

ll ways(ll n)
{
	if (n==1)
		return 1;
	if (dp[n]!=-1)
		return dp[n];
	ll res;
	if (n<=6)
	{
		res=1;
		for (ll i=1;i<=n-1;i++)
			res=(res%M + ways(n-i)%M)%M;
	}
	else
	{
		res=0;
		for (ll i=1;i<=6;i++)
			res=(res%M + ways(n-i)%M)%M;
	}
	return dp[n]=res;
}

int main()
{
	ll n;
	cin>>n;
	cout<<ways(n);
	return 0;
}

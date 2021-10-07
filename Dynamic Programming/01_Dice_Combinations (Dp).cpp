// Author: Akshay A Baiju
// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: Dp
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll 		long long
#define vll 	vector <ll>
const int M = 1e9+7;

vll dp(1e6+7,0);

int main()
{
	ll n;
	cin>>n;
	//initialization
	dp[0]=1;
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=6;j++)
		{
			if (i-j>=0)
				dp[i] = (dp[i]%M + dp[i-j]%M)%M;
		}
	}
	cout<<dp[n];
	return 0;	
}

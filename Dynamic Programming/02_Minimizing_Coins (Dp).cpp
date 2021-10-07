// Author: Akshay A Baiju
// Problem: Minimizing Coins
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1634
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: dp
// TC: O(n*x)
// SC: O(n+x)

#include<bits/stdc++.h>
using namespace std;
#define ll 		long long
#define vll 	vector <ll>
const int M = 1e9+7;

int main()
{
	ll n,x;
	cin>>n>>x;
	vll coins(n);
	for (ll i=0;i<n;i++)
		cin>>coins[i];
	//using Dp
	vll dp(x+1,-1);
	dp[0]=0;
	for (ll i=1;i<=x;i++)
	{
		ll c=LLONG_MAX;
		for (ll j=0;j<n;j++)
		{
			if (i-coins[j]>=0 && dp[i-coins[j]]!=-1)
				c=min(c,dp[i-coins[j]]);
		}
		if (c==LLONG_MAX)
			dp[i]=-1;
		else
			dp[i]=c+1;
	}
	cout<<dp[x];
	return 0;
}

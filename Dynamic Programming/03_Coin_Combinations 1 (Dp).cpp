// Author: Akshay A Baiju
// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1635
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
	vll dp(x+1,0);
	dp[0]=1;
	for (ll i=1;i<=x;i++)
	{
		ll c=0;
		for (ll j=0;j<n;j++)
		{
			if (i-coins[j]>=0)
				c = (c%M + dp[i-coins[j]]%M)%M;
		}
		dp[i]=c;
	}
	cout<<dp[x];
	return 0;
}

// Author: Akshay A Baiju
// Problem: Coin Combinations II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1636
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: dp
// TC: O(n*x)
// SC: O(n*x)

#include<bits/stdc++.h>
using namespace std;
#define ll 		long long
#define vll 	vector <ll>
const int M = 1e9+7;

int main()
{
	int n,x;
	cin>>n>>x;
	vector <int> coins(n);
	for (int i=0;i<n;i++)
		cin>>coins[i];
	sort(coins.begin(),coins.end());
	//using Dp - top down
	int dp[n+1][x+1];
	//dp[i][j] = no of ways to form sum j using i elements of the array
	for (int i=0;i<=n;i++)
		dp[i][0]=1;
	for (int i=1;i<=x;i++)
		dp[0][i]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=x;j++)
		{
			if (j-coins[i-1]>=0)
				dp[i][j] = (dp[i-1][j]%M + dp[i][j-coins[i-1]]%M)%M;
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][x];
	return 0;
}

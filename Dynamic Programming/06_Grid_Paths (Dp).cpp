// Author: Akshay A Baiju
// Problem: Grid Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1638
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: dp
// TC: O(n*n)
// SC: O(n*n)

#include<bits/stdc++.h>
using namespace std;
#define ll 		long long
#define vll 	vector <ll>
const int M = 1e9+7;

int main()
{
	//using Dp - top down
	int n;
	cin>>n;
	vector <string> grid(n);
	int dp[n][n];
	for (int i=0;i<n;i++)
	{
		cin>>grid[i];
		for (int j=0;j<n;j++)
		{
			if (grid[i][j]=='.')
				dp[i][j]=-1;
			else
				dp[i][j]=0;
		}
	}
	if (grid[0][0]=='*' || grid[n-1][n-1]=='*')
	{
		cout<<0;
		return 0;
	}
	//initilization
	int i;
	for (i=0;i<n && grid[0][i]=='.';i++)
		dp[0][i]=1;
	for (;i<n;i++)
		dp[0][i]=0;
	for (i=1;i<n && grid[i][0]=='.';i++)
		dp[i][0]=1;
	for (;i<n;i++)
		dp[i][0]=0;
	//iterative
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<n;j++)
		{
			if (dp[i][j]!=0)
				dp[i][j] = (dp[i-1][j]%M + dp[i][j-1]%M)%M;
		}
	}
	cout<<dp[n-1][n-1];
	return 0;
}

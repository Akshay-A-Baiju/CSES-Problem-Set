// Author: Akshay A Baiju
// Problem: Book Shop
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1158
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: dp (0-1 Knapsack)
// TC: O(n*x)
// SC: O(n*x)

#include<bits/stdc++.h>
using namespace std;
#define ll 		long long
#define vll 	vector <ll>
const int M = 1e9+7;

int main()
{
  //0-1 Knapsack
	int n,x;
	cin>>n>>x;
	vector <int> h(n),s(n);
	for (int i=0;i<n;i++)
		cin>>h[i];
	for (int i=0;i<n;i++)
		cin>>s[i];
	//using 0-1 Knapsack, Dp
	int dp[n+1][x+1];
	//intialization
	for (int i=0;i<=x;i++)
		dp[0][i]=0;
	for (int i=1;i<=n;i++)
		dp[i][0]=0;
	//iterative
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=x;j++)
		{
			if (j-h[i-1]>=0)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i-1]]+s[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][x];
	return 0;
}

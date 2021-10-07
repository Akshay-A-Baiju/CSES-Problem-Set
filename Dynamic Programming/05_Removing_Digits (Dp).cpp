// Author: Akshay A Baiju
// Problem: Removing Digits
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1637
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag: dp
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll 		long long
#define vll 	vector <ll>
const int M = 1e9+7;

int dp[1000007];

int minSteps(int n)
{
	if (n>=1 && n<=9)
		return dp[n]=1;
	if (dp[n]!=-1)
		return dp[n];
	int m=n;
	vector <int> digits;
	//we should not add 0 to the digits arrays, as it will result in infinite recursive call
	while (m)
	{
		int rem=m%10;
		if (rem!=0)
			digits.push_back(rem);
		m/=10;
	}
	int res=INT_MAX;
	for (int i=0;i<digits.size();i++)
		res=min(res,minSteps(n-digits[i]));
	return dp[n]=res+1;
}


int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<minSteps(n);
	return 0;
}

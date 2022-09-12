/* Recursive solution causes runtime error in CSES due to recursive stack overflow */

#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int M=1e9+7;
const ll inf=1e18;

vector <ll> c;
vector <vector<ll>> dp;

// dp[i][j]=ways to produce money i using coins in range [0,j]

ll ways(ll i, ll j)
{
	if (i==0) return 1;
	if (j<0) return 0;
	if (dp[i][j]!=-1) return dp[i][j];
	ll ans=0;
	for (ll take=0;i-take>=0;take+=c[j])
		ans=(ans+ways(i-take,j-1))%M;
	return dp[i][j]=ans;
}

int main()
{
	ll n,x; cin>>n>>x;
	c.resize(n);
	dp.resize(x+1, vector <ll> (n,-1));
	for (auto &it: c) cin>>it;
	cout<<ways(x,n-1);
	return 0;
}

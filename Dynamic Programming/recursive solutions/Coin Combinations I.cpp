#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int M=1e9+7;
const ll inf=1e18;

vector <ll> c;
vector <ll> dp(1e6+7,-1);

ll ways(ll x)
{
	if (x<0) return 0;
	if (x==0) return 1;
	if (dp[x]!=-1) return dp[x];
	ll ans=0;
	for (auto &it: c)
		ans=(ans+ways(x-it))%M;
	return dp[x]=ans;
}

int main()
{
	ll n,x; cin>>n>>x;
	c.resize(n);
	for (auto &it: c) cin>>it;
	cout<<ways(x);
	return 0;
}

#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int M=1e9+7;
const ll inf=1e18;

vector <ll> c;

ll ways(ll x)
{
	vector <ll> dp(x+1);
	dp[0]=1;
	for (ll i=1;i<=x;i++)
	{
		ll ans=0;
		for (auto &it: c)
		{
			if (i-it>=0)
				ans=(ans+dp[i-it])%M;
		}
		dp[i]=ans;
	}
	return dp[x];
}

int main()
{
	ll n,x; cin>>n>>x;
	c.resize(n);
	for (auto &it: c) cin>>it;
	cout<<ways(x);
	return 0;
}

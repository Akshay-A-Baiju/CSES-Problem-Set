#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int M=1e9+7;
const ll inf=1e18;

vector <ll> c;
vector <ll> dp(1e6+7,-1);

ll minCoins(ll x)
{
    if (x<0) return inf;
    if (x==0) return 0;
    if (dp[x]!=-1) return dp[x];
    ll ans=inf;
    for (auto &it: c)
        ans=min(ans,1+minCoins(x-it));
    return dp[x]=ans;
}

int main()
{
    int n,x; cin>>n>>x;
    c.resize(n);
    for (auto &it: c) cin>>it;
    ll ans=minCoins(x);
    (ans==inf)?cout<<-1:cout<<ans;
    return 0;
}

#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int M=1e9+7;
const ll inf=1e18;

vector <ll> c;

ll minCoins(ll x)
{
    vector <ll> dp(x+1);
    dp[0]=0;
    for (ll i=1;i<=x;i++)
    {
        ll ans=inf;
        for (auto &it: c)
        {
            if (i-it>=0)
                ans=min(ans,1+dp[i-it]);
        }
        dp[i]=ans;
    }
    return dp[x];
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

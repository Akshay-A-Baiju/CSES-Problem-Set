#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int M=1e9+7;

ll ways(ll n)
{
    vector <ll> dp(n+1);
    dp[0]=1;
    for (ll i=1;i<=n;i++)
    {
        dp[i]=0;
        for (ll j=1;j<=6;j++)
        {
            if (i-j>=0) dp[i]=(dp[i]+dp[i-j])%M;
        }
    }
    return dp[n];
}

int main()
{
    int n; cin>>n;
    cout<<ways(n);
    return 0;
}

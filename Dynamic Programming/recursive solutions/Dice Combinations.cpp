#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int M=1e9+7;

vector <ll> dp(1e6+7,-1);

ll ways(ll n)
{
    if (n<0) return 0;
    if (n==0) return 1;
    if (dp[n]!=-1) return dp[n];
    ll ans=0;
    for (ll i=1;i<=6;i++)
        ans=(ans+ways(n-i))%M;
    return dp[n]=ans;
}

int main()
{
    int n; cin>>n;
    cout<<ways(n);
    return 0;
}

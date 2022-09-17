// Author: Akshay A Baiju
// Problem: Subordinates
// URL: https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"   //not to be used in interactive problems
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.141592653589793238462

const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;

vector <ll> sbtree;

void dfs(ll node, vector <ll> adj[])
{
    sbtree[node]=1;
    for (auto &it: adj[node])
    {
        dfs(it,adj);
        sbtree[node]+=sbtree[it];
    }
}

void solve()
{
    ll n; cin>>n;
    sbtree.resize(n);
    vector <ll> adj[n];
    for (ll i=1;i<n;i++)
    {
        ll par; cin>>par; par--;
        adj[par].push_back(i);
    }
    dfs(0,adj);
    for (auto &it: sbtree)
        cout<<it-1<<" ";
}

int main()
{
    sync;
    int t=1;
    // cin>>t;
    for (int test=1;test<=t;test++)
    {
        solve();
        cout<<endl;
    }
    return 0;
}

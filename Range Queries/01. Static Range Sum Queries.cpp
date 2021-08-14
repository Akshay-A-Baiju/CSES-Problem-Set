// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1646
// Problem tags : prefix sum on 1D array
// TC : O(n*q)    -> O(1) for queries
// SC : O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long
#define vi                  vector <int>
#define vll                 vector <ll>
#define vvll                vector <vll>
#define pii                 pair <int,int>
#define pll                 pair <ll,ll>
#define ms(a,x)             memset (a,x,sizeof(a))
#define rep(i,a,n)          for (int i=a;i<n;i++)
#define rrep(i,n,a)         for (int i=n;i>=a;i--)
#define pb                  push_back
#define pf                  push_front
#define ppb                 pop_back
#define umap                unordered_map
#define uset                unordered_set
#define all(v)              v.begin(), v.end()
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

vll prefixSum(200007,0);

void solve()
{ 
    ll n,q;
    cin>>n>>q;
    vll v(n);
    scan_vector(v,n);
    //computing prefix array which stores the sum of elements from 0 to the index
    for (ll i=1;i<=n;i++)
        prefixSum[i]=prefixSum[i-1]+v[i-1];
    while (q--)
    {
        ll lo,hi;
        cin>>lo>>hi;
        ll ans=prefixSum[hi]-prefixSum[lo-1];
        cout<<ans<<endl;
    }
}

int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    //cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}

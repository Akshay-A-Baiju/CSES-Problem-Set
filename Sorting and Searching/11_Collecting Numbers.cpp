// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/2216
// Problem tags : hashing, logical
// TC : O(n)
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

void solve()
{
    //we observe that if the index of (i+1) lies to the left of the index of i for i in range [1,n]
    //we need to add a new round, use hashing/unordered map to store the index of 1,2,...,n
        
    ll n;
    cin>>n;
    vll v(n);
    vll hsh(n+1,0);
    for (ll i=0;i<n;i++)
    {
        cin>>v[i];
        hsh[v[i]]=i+1;
    }
    ll round=1;
    for (ll i=1;i<=n-1;i++)
    {
        if (hsh[i+1]<hsh[i])
            round++;
    }
    cout<<round;
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
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}

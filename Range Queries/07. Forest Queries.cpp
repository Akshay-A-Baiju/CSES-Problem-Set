// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1652
// Problem tags : prefix sum on 2D array
// TC : O(n^2)  //O(1) for query
// SC : O(n^2)

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

ll prefixSum[1007][1007];

void solve()
{
    //using prefix 2D array to store the no of trees from (0,0) to (x,y)    
    ll n,q;
    cin>>n>>q;
    for (ll i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for (ll j=1;j<=n;j++)
        {
            prefixSum[i][j]=prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1];
            if (s[j-1]=='*')
                prefixSum[i][j]++;
        }
    }
    while (q--)
    {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll trees=prefixSum[x2][y2]-prefixSum[x2][y1-1]-prefixSum[x1-1][y2]+prefixSum[x1-1][y1-1];
        cout<<trees<<endl;
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

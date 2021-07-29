// Author : Akshay A Baiju

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
#define desc()              greater <int>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v,n)   for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

void solve()
{
    //total ways to place 2 knights (without restriction) = {(n^2) * (n^2-1)}/2
    //restriction: knights dont attack each other
    //observation: in every 2*3 cell, 2 knights can attack each other in 2 ways, way1 = (n-1)*(n-2)*2ways
    //similarily for every 3*2 cells, way2 = (n-2)*(n-1)*2ways
    //Restricted ways = way1 + way2 = 4*(n-1)*(n-2)
    //Thus, total no of ways to place 2 knights (with restriction) = total ways - restricted ways
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++)
    {
        ll total=(i*i)*(i*i-1)/2;
        ll restricted=4*(i-1)*(i-2);
        ll ans=total-restricted;
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
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}

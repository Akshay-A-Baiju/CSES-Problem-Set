// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/2205

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

vector <string> generate(ll n)
{
    if (n==1)
    {
        vector <string> ans= {"0","1"};
        return ans;
    }
    vector <string> prev = generate(n-1), res;
    //adding 0 to front of each strings of prev result
    for (ll i=0;i<prev.size();i++)
        res.pb("0" + prev[i]);
    //adding 1 to front of each strings of prev result taken in reverse
    for (ll i=prev.size()-1;i>=0;i--)
        res.pb("1" + prev[i]);
    return res;
}

void solve()
{
    // observation : result (n) = 0 added to front of strings of result (n-1) & 1 added to front of strings of reverse result(n-1)
    // eg: n=1 ->  {"0","1"}
    // n=2 -> { "00", "01"} & {"11", "10"}
    // n=3 -> { "000", "001", "011", "010"} & { "110", "111", "101", "100"}
    // since we need solution of set of strings of n-1, we have sub problem, hence recursion

    ll n;
    cin>>n;
    vector <string> vec=generate(n);
    for (auto &it : vec)
        cout<<it<<endl;
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

// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1622
// Problem tags : recursion, backtracking

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

set <string> res;

void generate(string &s, umap<ll, bool> &mp, string &str)
{
    ll true_count=0;     //count==s.size() means 'str' is a permutation, else continue permutation
    for (auto &it : mp)
    {
        if (it.second)
            true_count++;
    }
    if (true_count==s.size())   // or str.size()==s.size()
    {
        res.insert(str);
        return;
    }
    else
    {
        for (auto &it: mp)
        {
            if (!it.second)
            {
                it.second=true;
                str.pb(s[it.first]);
                generate(s,mp,str);
                //now backtracking for other possiblities
                it.second=false;
                str.ppb();
            }
        }
    }
}

void solve()
{   
    // idea: maintaining a map which stores information if ith charcter of string s can be considered
    // starting which an empty string, and we have choice to fill each ith position, hence recursion
    // continue till all the ith character of string has being considered / string str.size() == s.size()
    string s,str="";
    cin>>s;
    umap<ll, bool> mp;
    for (ll i=0;i<s.size();i++)
        mp[i]=false;    //taken in string
    generate(s,mp,str);
    cout<<res.size()<<endl;
    for (auto &it: res)
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

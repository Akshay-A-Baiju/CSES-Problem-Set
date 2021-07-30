// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1622
// Problem tags : recursion, backtracking, swap
// TC : O(n*n!)
// SC : O(n) //for recursion depth, O(n*n!) //including set storage of permutations

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
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

set <string> st;

void permute(string &s, ll index)
{
    if (index==s.size()-1)
    {
        st.insert(s);
        return;
    }
    for (ll i=index;i<s.size();i++)
    {
        swap(s[i],s[index]);
        permute(s,index+1);
        swap(s[i],s[index]);    //backtracking
    }
}

void solve()
{
    //string permutation using recursion+backtracking (Swapping method)
    //idea of swapping: all characters must come in every indices

    string s;
    cin>>s;
    permute(s,0);
    cout<<st.size()<<endl;
    for (auto &it : st)
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

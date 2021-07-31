// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1640
// Problem tags : binary search, sorting, map
// TC : O(nlogn)
// SC : O(n)    //to store map

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

void solve()
{
    //greedy algo: sort the vector and check for an element, if (x-element) is present in the vector or not using Binary Search
    //use map to store the initial index of elements before sorting

    ll n,x;
    cin>>n>>x;
    vll v(n);
    map<ll,vector<ll>> mp;     //map stores the elements and their indices in a vector
                               //so as to counter cases when element=x/2, its freq should be >=2 for possible answer, else impossible
    for (ll i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]].pb(i+1);
    }
    sort(all(v));
    for (ll i=0;i<n && v[i]<=x;i++)
    {
        if (binary_search(all(v),x-v[i]))
        {
            if (v[i]==x/2 && mp[v[i]].size()>1)
            {
                cout<<mp[v[i]][0]<<" "<<mp[v[i]][1];
                return;
            }
            else if (v[i]!=x/2)
            {
                cout<<mp[v[i]][0]<<" "<<mp[x-v[i]][0];
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
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

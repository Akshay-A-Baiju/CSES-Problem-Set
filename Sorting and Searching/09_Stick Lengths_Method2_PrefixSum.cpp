// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1074
// Problem tags : greedy, prefix sum, sorting, logical
// TC : O(nlogn)
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
    //first sort the vectors
    //now construct 2 prefix vectors :prefix1[i] = stores the no of sticks to add from index [0,i-1] so that the sticks becomes to length stick[i]
    //prefix2[i] = stores the no of sticks to substract from index [n-1,i+1] so that the sticks becomes to length stick[i]
    //thus no of sticks required to add/sub to make all sticks equal to stick[i] = prefix1[i] + prefix2[i]
    //Thus find the minimum of prefix1[i] + prefix2[i] for i=[0,n-1]

    ll n;
    cin>>n;
    vll v(n);
    scan_vector(v,n);
    sort(all(v));
    vll prefix_sum1(n),prefix_sum2(n);
    prefix_sum1[0]=0;
    for (ll i=1;i<n;i++)
        prefix_sum1[i]=prefix_sum1[i-1]+(i*(v[i]-v[i-1]));
    prefix_sum2[n-1]=0;
    for (ll i=n-2;i>=0;i--)
        prefix_sum2[i]=prefix_sum2[i+1]+((n-i-1)*(v[i+1]-v[i]));
    ll ans=LLONG_MAX;
    for (ll i=0;i<n;i++)
        ans=min(ans,prefix_sum1[i]+prefix_sum2[i]);
    cout<<ans;
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

// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1623
// Problem tag : recursion

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
#define print_vector(v)   	for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

ll ans=LLONG_MAX;

void recurr(vll &weights, ll index, ll n, ll group1, ll group2)
{
    if (index==n)
        ans=min(ans,abs(group1-group2));
    else
    {
        //2 choice, goes to group1 or group 2
        recurr(weights,index+1,n,group1+weights[index],group2); //choice 1
        recurr(weights,index+1,n,group1,group2+weights[index]); //choice 2
    }
}

void solve()
{
    //as we have 2 choice for each weight: either goes in group 1 or group 2, and decision to make, hence recursion
     
    ll n;
    cin>>n;
    vll weights(n);
    scan_vector(weights,n);
    recurr(weights,0LL,n,0LL,0LL);
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

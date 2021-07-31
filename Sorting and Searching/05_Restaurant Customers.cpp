// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1619
// Problem tags : logical, sorting, greedy
// TC : O(nlogn)
// SC : O(n)    //to store vector of pair

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
    //each customer will generate 2 events -> enter and exit
    //thus if we make a pair <entry index, +1> for entry and pair <exit index, -1> for each customer
    //store them in a vector and sort them, then at any point the maximum sum of entry & exit will be required answer

    ll n;
    cin>>n;
    vector <pair<ll,ll>> event;
    for (ll i=0;i<n;i++)
    {
        ll start,end;
        cin>>start>>end;
        event.pb({start,1});
        event.pb({end,-1});
    }
    sort(all(event));
    ll ans=0,sum=0;
    for (auto &pr: event)
    {
        sum+=pr.second;
        ans=max(ans,sum);
    }
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

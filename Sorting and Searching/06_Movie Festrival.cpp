// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1629
// Problem tags : logical, sorting, greedy
// TC : O(nlogn)
// SC : O(n)    //create vector of pair

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

bool cmp(pair <ll,ll> a, pair <ll,ll> b)
{
    if (a.second>b.second)
        return false;
    else if (a.second==b.second)
        return a.first<b.first;
    else
        return true;
}

void solve()
{ 
    //interval scheduling problem (greedy algo)
    //sort all the movie intervals according to ending time, now moving over the intervals
    //count the number of non - overlapping inytervals -> maximum due to greedy
    
    ll n;
    cin>>n;
    vector <pair<ll,ll>> movie(n);
    for (ll i=0;i<n;i++)
    {
        ll start,end;
        cin>>start>>end;
        movie[i]={start,end};
    }
    sort(all(movie),cmp);
    ll full=1,prev=0;
    for (ll i=1;i<n;i++)
    {
        if (movie[i].first>=movie[prev].second)
        {
            full++;
            prev=i;
        }
    }
    cout<<full;
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

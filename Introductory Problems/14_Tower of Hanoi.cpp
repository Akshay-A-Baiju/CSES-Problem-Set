// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/2165

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

vector <pair<ll,ll>> step;
ll no_of_steps;

void towerOfHanoi(ll n,ll start,ll final,ll middle)
{
    if (n==1)
    {
        step.pb({start,final});
        no_of_steps++;
        return;
    }
    else
    {
        //move top (n-1) discs from start to middle(intermediate) tower using final(destination) tower
        towerOfHanoi(n-1,start,middle,final);
        //move the biggest disc from start to final tower directly
        step.pb({start,final});
        no_of_steps++;
        //move the (n-1) discs from middle to final tower using start tower
        towerOfHanoi(n-1,middle,final,start);
    }
}

void solve()
{   
    ll n;
    cin>>n;
    towerOfHanoi(n,1,3,2);
    cout<<no_of_steps<<endl;
    for (auto &it: step)
        cout<<it.first<<" "<<it.second<<endl;
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

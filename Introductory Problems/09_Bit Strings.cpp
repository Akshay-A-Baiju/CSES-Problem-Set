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

ll binExpIter(ll a, ll b)
{
    //Iterative Binary Exponentiation
    //TC: O(logb) for a^b
    //default modulo M = 1e9+7

    //For large value of a and M in order 1e18, use binMultiply(a,a) and binMultiply(ans,a) to prevent overflow

    ll ans=1;
    while (b)
    {
        if (b&1)
            ans=(ans*a)%M;   //ans=binMultiply(ans,a);
        a=(a*a)%M;           //a=binMultiply(a,a);
        b=b>>1;
    }
    return ans;
}

void solve()
{
    //no of possible bit strings = 2^n, for n
    ll n;
    cin>>n;
    cout<<binExpIter(2LL,n);
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

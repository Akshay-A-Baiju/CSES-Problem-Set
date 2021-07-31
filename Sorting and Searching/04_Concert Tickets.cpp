// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1091
// Problem tags : STL, set, logical, greedy, sorting, lower_bound
// TC : O(nlogn + mlogn)
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
#define desc()              greater <int>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

void solve()
{    
    ll n,m;
    cin>>n>>m;
    vll ticket(n),customer(m);
    set<pair<ll,ll>> st;    //stores the pair <ticket, index> in sorted order
    for (ll i=0;i<n;i++)
    {
        cin>>ticket[i];
        st.insert({ticket[i],i});
    }
    for (ll i=0;i<m;i++)
    {
        cin>>customer[i];
        auto it=st.lower_bound({customer[i]+1,0});
        if (it==st.begin())     //no ticket with equal or lower price
            cout<<-1<<endl;
        else if (it==st.end())  //lower bound does not exist, then lower ticket price is the last pair in set (if set is not empty)
        {
            if (!st.empty())
            {
                --it;
                cout<<it->first<<endl;
                st.erase(it);
            }
            else
                cout<<-1<<endl;
        }
        else
        {
            --it;
            cout<<it->first<<endl;
            st.erase(it);
        }
    }
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

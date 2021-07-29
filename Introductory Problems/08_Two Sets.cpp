// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1092

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
#define pb push_back
#define endl "\n"
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

void solve()
{
	//observation: to divide sum=1+2+..+n into 2 sets of equal sum, the sum should be even, else not possible
	//keep placing n,n-1,...,2,1 optimally in 2 sets. i.e. if sum of set1 > set2, place next in set2, and so on
	
    ll n;
    cin>>n;
    ll sum=n*(n+1)/2;
    if (sum&1)
    {
        cout<<"NO";
        return;
    }
    vi v1,v2;
    ll sum_v1=0,sum_v2=0;
    while (n)
    {
        if (sum_v1<sum_v2)
        {
            v1.pb(n);
            sum_v1+=n;
        }
        else
        {
            v2.pb(n);
            sum_v2+=n;
        }
        n--;
    }
    cout<<"YES\n";
    cout<<v1.size()<<endl;
    for (auto &it: v1)
        cout<<it<<" ";
    cout<<endl;
    cout<<v2.size()<<endl;
    for (auto &it: v2)
        cout<<it<<" ";     
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

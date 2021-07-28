// Author : Akshay A Baiju
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
#define pb push_back
#define endl "\n";
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N=1e9+7;

void solve()
{
    ll n,add=0;
    cin>>n;
    vll v(n);
    for (ll i=0;i<n;i++)
    {
        cin>>v[i];
        if (i>0)
        {
            if (v[i]<v[i-1])
            {
                add+=v[i-1]-v[i];
                v[i]=v[i-1];
            }
        }
    }
    cout<<add;     
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

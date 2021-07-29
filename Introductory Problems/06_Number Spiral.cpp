// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1071

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
    ll x,y,ans=0;
    cin>>x>>y;
    if (x>=y)   //start with row
    {
        if (x&1)
            ans=(x-1)*(x-1)+y;
        else
            ans=x*x-y+1;
    }
    else    //start with column
    {
        if (y&1)
            ans=y*y-x+1;
        else
            ans=(y-1)*(y-1)+x;
    }
    cout<<ans;    
}
 
int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}

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
    ll n;
    cin>>n;
    cout<<n<<" ";
    while (n!=1)
    {
        if (n&1)
            n=n*3+1;
        else
        n=n>>1;
        cout<<n<<" ";
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

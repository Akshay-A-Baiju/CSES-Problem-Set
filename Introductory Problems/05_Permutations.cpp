// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1070
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
    if (n<5)
    {
    	if (n==1)
    	cout<<1;
    	else if (n==4)
    	cout<<2<<" "<<4<<" "<<1<<" "<<3;
		else
        cout<<"NO SOLUTION";
    }
    else
    {
        int ch[n];
        ll p=1,i;
        for (i=0;i<n;i=i+2,p++)
            ch[i]=p;
        for (i=1;i<n;i=i+2,p++)
            ch[i]=p;
        for (i=0;i<n;i++)
            cout<<ch[i]<<" ";
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

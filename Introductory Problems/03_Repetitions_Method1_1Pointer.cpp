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
	//using normal 1-pointer
    string s;
    cin>>s;
    int length=1,mx=0;
    for (int i=1;i<s.size();i++)
    {
        if (s[i]!=s[i-1])
        {
            if (length>mx)
                mx=length;
            length=1;
        }
        else
            length++;
    }
    cout<<max(mx,length);     
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

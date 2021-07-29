// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1755

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

void solve()
{
	//observation : to be palindrome, for an even length string, all char frequency should be even
	//for odd length string, atmost one char can have odd frequnecy (and must be in middle) and the rest should have even frequency
	
    string s;
    cin>>s;
    ll len=s.size();
    char ch[len];
    umap<char,ll> mp;
    for (ll i=0;i<len;i++)
        mp[s[i]]++;
    ll odd=0,even=0;
    char odd_ch;
    for (auto &it: mp)
    {
        if (it.second&1)
        {
            odd++;
            odd_ch=it.first;
        }
        else
            even++;
    }
    if (odd>1 || (odd==1 && len%2==0))
        cout<<"NO SOLUTION";
    else
    {
        ll i=0,j=len-1;   //using 2 pointers, i to move forward from start, j to move backward from end
        //putting the odd in middle (of odd length string, only probabilty);
        if (odd==1)
        {
            ch[len/2]=odd_ch;
            mp[odd_ch]--;
        }
        //now all chars are even in frequency
        for (auto &it: mp)
        {
            ll f=it.second>>1;
            //forward
            while (f--)
            {
                ch[i++]=it.first;
                ch[j--]=it.first;
            }
        }
        for (auto &it: ch)
        cout<<it;
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

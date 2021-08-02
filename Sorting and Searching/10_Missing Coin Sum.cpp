// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/2183
// Problem tags : sorting, logical
// TC : O(nlogn)
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
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

void solve()
{  
    //logic: first sort the vector, then take sum=1, intially
    //traverse the vector, if the element is greater than sum, sum is the required answer else add the element to sum.
    //the reason of adding the element to sum is because, and number between [sum+1,sum+element-1] can be formed using the element and previous elements

    ll n;
    cin>>n;
    vll v(n);
    scan_vector(v,n);
    sort(all(v));
    ll sum=1,i=0;
    while (i<n)
    {
        if (v[i]>sum)
        {
            cout<<sum;
            return;
        }
        sum+=v[i];
        i++;
    }
    cout<<sum;   //if numbers are 1,2,....,n, then while breaks and sum=n*(n+1)/2 + 1(initially), hence answer would be sum
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

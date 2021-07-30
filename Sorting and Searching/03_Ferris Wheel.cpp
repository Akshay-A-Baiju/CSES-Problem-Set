// Author : Akshay A Baiju
// Problem link : https://cses.fi/problemset/task/1090
// Problem tags : sorting, greedy, 2-pointer, logical
// TC : O(nlogn)
// SC : O(1) except storing input vector

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
    //sort the weights
    //using 2-pointers, i-pointer to move forward from start, j-pointer to move backward from end
    //if weight[i]+weight[j]<=x, they can be fitted into a gondalo, else weight[j] needs an individual gandola
    //decrement j till weight[i]+weight[j]<=x
    //fit them into a gondola, update i,j
    //continue till i<=j

    ll n,x;
    cin>>n>>x;
    vll weight(n);
    scan_vector(weight,n);
    sort(all(weight));
    ll i=0,j=n-1,gondolas=0;
    while (i<=j)
    {
        while (i<j && weight[i]+weight[j]>x)
        {
            j--;
            gondolas++; //as weight[j] will need a seperate gondola
        }
        gondolas++;
        j--;
        i++;
    }
    cout<<gondolas;
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

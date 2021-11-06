// Author : Akshay A Baiju
// Problem link : hhttps://cses.fi/problemset/task/1650
// Contest : 
// Problem tags : segment tree
// TC : O(n+qlogn)
// SC : O(n)
 
#include "bits/stdc++.h"
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
 
#define ll                  long long
#define ull                 unsigned long long
#define vi                  vector <int>
#define vll                 vector <ll>
#define vvll                vector <vll>
#define pii                 pair <int,int>
#define pll                 pair <ll,ll>
#define vpll                vector <pll>
#define ms(a,x)             memset (a,x,sizeof(a))
#define rep(i,a,n)          for (int i=a;i<n;i++)
#define rrep(i,n,a)         for (int i=n;i>=a;i--)
#define pb                  push_back
#define pf                  push_front
#define ppb                 pop_back
#define ff                  first
#define ss                  second
#define ins                 insert
#define umap                unordered_map
#define uset                unordered_set
#define YY		              cout<<"YES"
#define NN		              cout<<"NO"
#define all(v)              v.begin(), v.end()
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v)      for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define oset		          tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
	#define debug(x)	    cerr<<#x<<" = "; _print(x); cerr<<"\n";
#else
	#define debug(x)
#endif
 
const int M = 1e9+7;
const int N = 2e5+7;
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
vll sgtree(4*N,0);			//default value
 
ll merge_sgtree(ll a, ll b)
{
	return (a^b);
}
 
void build_sgtree(vll &v, ll ind, ll lo, ll hi)
{
	//TC: O(n)
	if (lo==hi)				//if leaf node
	{
		sgtree[ind]=v[lo];
		return;
	}
	ll mid=(hi+lo)>>1;
	build_sgtree(v,2*ind+1,lo,mid);
	build_sgtree(v,2*ind+2,mid+1,hi);
	sgtree[ind]=merge_sgtree(sgtree[2*ind+1],sgtree[2*ind+2]);
}
 
ll query(ll ind, ll lo, ll hi, ll l, ll r)
{
	//TC: O(logn)
	//3 cases
	if (lo>=l && hi<=r)		//complete overlap
		return sgtree[ind];
	else if (lo>r || hi<l)	//no overlap, return default value
		return 0;
	else					//partial overlap
	{
		ll mid=(hi+lo)>>1;
		ll left=query(2*ind+1,lo,mid,l,r);
		ll right=query(2*ind+2,mid+1,hi,l,r);
		return merge_sgtree(left,right);
	}
}
 
 
void solve()
{
	ll n,q;	cin>>n>>q;
	vll v(n);
	scan_vector(v);
	build_sgtree(v,0,0,n-1);
	while (q--)
	{
		ll l,r;	cin>>l>>r;
		cout<<query(0,0,n-1,l-1,r-1)<<endl;
	}
}
 
int main()
{
	#ifndef ONLINE_JUDGE
		// freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		clock_t clk = clock();
	#endif
	sync;
	int t=1;
	// cin>>t;
	for (int test=1;test<=t;test++)
	{
		// cout<<"Case #"<<test<<": ";
		solve();
		cout<<endl;
	}
	#ifndef ONLINE_JUDGE
		cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
	#endif
	return 0;
}

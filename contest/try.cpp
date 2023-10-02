// Vipul kumar--Welcome to coding workspace
#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using osetg = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ul;
#define setbits(x) __builtin_popcountll(x)
#define lp(i, n) for (ll i = 0; i < n; i++)
#define ff first
#define ss second
#define pi 3.14159265358979323846
#define l_b lower_bound
#define u_b upper_bound
#define sps(x, y) fixed << setprecision(y) << x
#define all(v) v.begin(), v.end()
const ll M = 1e9 + 7;
bool solve(ll ind,ll n,ul tar,vector<ul> vec,ul sum,ll sz){
    if(sum==tar and n==0) return true;
    if(sum>tar) return false;
    if(ind>=sz or n<0) return false;
    bool tak = solve(ind+1,n-1,tar,vec,sum+vec[ind],sz);
    bool not_take = solve(ind+1,n,tar,vec,sum,sz);
    return (tak or not_take);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ul> vec;
        vec.push_back(1);
        vector<ul> fib(48);
        fib[0]=1;
        fib[1]=1;
        for(int i=2;i<=47;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        ul tar = fib[n]*fib[n+1];
        int k=2;
        // cout<<tar<<endl;
        while(fib[k]*fib[k]<=tar){
            vec.push_back(fib[k]*fib[k]);
            vec.push_back(fib[k]*fib[k]);
            k++;
        }
        bool ans = solve(0,n,tar-1,vec,0,vec.size());
        ans?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
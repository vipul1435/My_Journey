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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<ll> vec(n-1);
        lp(i,n-1) cin>>vec[i];
        vector<ll> ans;
        ans.emplace_back(vec[0]);
        n--;
        for(int i=1;i<n;i++){
            if(vec[i-1]<vec[i]){
                ans.emplace_back(min(vec[i-1],vec[i]));
            } else {
                ans.emplace_back(vec[i]);
            }
        }
        if(vec[n-1]>ans[n-1]){
            ans.emplace_back(vec[n-1]);
        } else {
            ans.emplace_back(ans[n-1]);
        }
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
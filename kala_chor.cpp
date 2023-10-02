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
#define flag(fl) fl ? cout << "YES\n" : cout << "NO\n"
#define endl "\n"
#define lp(i, n) for (ll i = 0; i < n; i++)
#define lpp(i, n) for (ll i = 1; i < n; i++)
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
    #ifndef ONLINE_JUDGE
        freopen("output.txt","r",stdin);
        freopen("output1.txt","w",stdout);

    #endif
    ll t;
    cin >> t;
    ll dd=1;
    while (t--)
    {
        ul a,b,c;
        cin>>a>>b>>c;
        ul bun = a+2*1LL*b;
        ul patty = 2*1LL*a + 2*1LL*b;
        cout << "Case #" << dd << ": ";
        flag(bun>=c and patty>c);
        dd++;
    }
    return 0;
}
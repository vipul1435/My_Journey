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
ll solve(ll n, map<ll, ll> mp)
{
    if (!mp.count(0))
        return 0;
    vector<ll> vec;
    for (auto it : mp)
    {
        vec.push_back(it.ff);
    }
    sort(all(vec));
    ll ma = vec.size();
    lp(i, vec.size())
    {
        if (i != vec[i])
        {
            ma = i;
            break;
        }
    }
    ll ans = ma*(mp[0]-1);
    for (auto it : mp)
    {
        if (it.ff < ma)
        {
            ll cmp =it.ff + ma * (it.ss - 1) + it.ff * (mp[0]-1);
            ans = min(ans, cmp);
        }
    }
    // ma = ma*(mp[0]-1);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        map<ll,ll> mp;
        lp(i, n)
        {
            ll k;
            cin >> k;
            mp[k]++;
        }
        cout << solve(n, mp) << endl;
    }
    return 0;
}
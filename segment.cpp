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
vector<unordered_map<int, int>> seg;
void build_seg(int ind, int low, int high, vector<int> &arr, vector<unordered_map<int, int>> &seg)
{
    if (low == high)
    {
        seg[ind][arr[low]]++;
        return;
    }
    int mid = (low + high) / 2;
    build_seg(2 * ind + 1, low, mid, arr, seg);
    build_seg(2 * ind + 2, mid + 1, high, arr, seg);
    for (auto it : seg[ind])
        seg[ind][it.first] = 0;
    for (auto it : seg[2 * ind + 1])
        seg[ind][it.first] += it.second;
    for (auto it : seg[2 * ind + 2])
        seg[ind][it.first] += it.second;
}
int range_query(int ind, int low, int high, int left, int right, int val)
{
    if (left > high or right < low)
    {
        return 0;
    }
    if (low >= left and high <= right)
    {
        if (seg[ind].count(val))
            return seg[ind][val];
        else
            return 0;
    }
    int mid = (low + high) / 2;
    int le = range_query(2 * ind + 1, low, mid, left, right, val);
    int re = range_query(2 * ind + 2, mid + 1, high, left, right, val);
    return le + re;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
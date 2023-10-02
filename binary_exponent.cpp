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
#define ff first
#define ss second
#define pi 3.14159265358979323846
#define l_b lower_bound
#define u_b upper_bound
#define sps(x, y) fixed << setprecision(y) << x
#define all(v) v.begin(), v.end()
const ll M = 1e9 + 7;
int  findSubsequence(int* arr, int n)
{
    int k=n;
    map<int, int> M;
    for (int i = 0; i < n; ++i)
        ++M[arr[i]];
    int* numCount = new int[k + 1]; 
    for (int i = 0; i <= k; ++i)
        numCount[i] = 0;
    for (auto p : M) {
        if (p.first <= k) {
            for (int i = 1;; ++i) {
                if (p.first * i > k)
                    break;
                numCount[p.first * i] += p.second;
            }
        }
        else
            break;
    }
    int lcm = 0, length = 0;
    for (int i = 1; i <= k; ++i) {
        if (numCount[i] > length) {
            length = numCount[i];
            lcm = i;
        }
    }
    return length;
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
        cin>>n;
        int arr[n];
        lp(i,n) cin>>arr[i];
        cout<<findSubsequence(arr,n)<<endl;
    }
    return 0;
}
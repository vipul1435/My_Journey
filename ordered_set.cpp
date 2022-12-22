// Vipul kumar--Welcome to coding workspace
#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
        // declaring orderd set
        pbds A;

        // inserting the element
        A.insert(23);
        A.insert(21);
        A.insert(1);
        A.insert(5);
        A.insert(10);

        // printing the value
        for (auto it : A)
            cout << it << " ";
        cout << endl;

        // Access the element by index
        cout << *A.find_by_order(1) << endl;
        cout << *A.find_by_order(2) << endl;

        // finding the number of element smaller then a give value
        cout << A.order_of_key(45) << endl;
        cout << A.order_of_key(10) << endl;

        // Lower bound of X-> first element greater or equal to X
        cout << *A.lower_bound(10) << endl;

        // Upper bound of X -> first element which is greater then X
        cout << *A.upper_bound(10) << endl;

        // erase -> by value
        cout << A.erase(10) << endl;

        for (auto it : A)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
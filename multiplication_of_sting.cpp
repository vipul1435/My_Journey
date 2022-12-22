#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define lp(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    vector<stack<int>> vec;
    int as = a.size();
    int bs = b.size();
    for (int i = bs - 1; i >= 0; i--)
    {
        stack<int> temp;
        lp(j, bs - 1 - i) temp.push(0);

        int bb = b[i] - '0';
        for (int j = as - 1; j >= 0; j--)
        {
            int aa = a[j] - '0';
            int pro = aa * bb;
            temp.push(pro);
        }
        lp(j, i)
        {
            temp.push(0);
        }

        vec.push_back(temp);
    }
    int k = vec[0].size();
    long long arr[k];
    lp(i, k) arr[i] = 0;
    for (auto it : vec)
    {
        int i = 0;
        while (!it.empty())
        {
            arr[i] += it.top();
            it.pop();
            i++;
        }
        cout << endl;
    }
    long long rem = 0;
    cout << endl;
    for (int i = k - 1; i >= 0; i--)
    {
        int l = arr[i];
        l += rem;
        rem = l / 10;
        arr[i] = l % 10;
    }
    arr[0] += (rem * 10);
    string finans = "";
    string te;
    lp(i, k)
    {
         te = to_string(arr[i]);
        finans += te;
    }
    cout << finans;
    return 0;
}
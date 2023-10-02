#include <bits/stdc++.h>
using namespace std;
int recur_power(int a, int b)
{
    if (b == 0)
        return 1;
    int x = recur_power(a, b / 2);
    if (b & 1)
    {
        return x * x * a;
    }
    else
    {
        return x * x;
    }
}
int binary_exponential(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        b = b >> 1;
        a *a;
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 1, 1, 3, 5, 5, 1, 1};
    vector<int>::iterator it;
    it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));
    for (auto p : v)
        cout << p << " ";
    cout << endl;
}
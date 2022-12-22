// Problem statement ---------
//  to find the number of nodes at a given level using bfs
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> ar[N];
vector<bool> vis(N, 0);
int bfs(int ver, int val, int v)
{
    deque<int> d;
    d.push_back(ver);
    vis[ver] = 1;
    vector<int> lev(v, 0);
    while (!d.empty())
    {
        int k = d.front();
        d.pop_front();
        // cout<<k<<" ";
        for (auto it : ar[k])
        {
            if (!vis[it])
            {
                d.push_back(it);
                vis[it] = 1;
                lev[it] = (lev[k] + 1);
            }
        }
    }
    int cnt = 0;
    for (int i = ver; i < v; i++)
    {
        if (lev[i] == val)
            cnt++;
    }
    return cnt;
}
int main()
{
    int v;
    cin >> v;
    for (int i = 1; i < v; i++)
    {
        int z, x;
        cin >> z >> x;
        ar[z].push_back(x);
        ar[x].push_back(z);
    }
    int val;
    cin >> val;
    cout << bfs(0, val, v) << endl;
}
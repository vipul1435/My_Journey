/* this problem is based on --------------->
a directed graph is given and find the node from where we can visit hole graph; */
// IF THERE ARE MORE THEN ONE  MOTHER OUTPUT ANY ONE

// APROACH
// trivia method is visit all vertices from all nodes. this is insufficient for large graph as it's complexity is O(V(E+V))
// best algorith work in O(E+V)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<bool> vis(N, 0);
vector<int> ar[N];
void dfs(int ver)
{
    vis[ver] = 1;
    for (auto child : ar[ver])
    {
        if (!(vis[child]))
            dfs(child);
    }
}
int find_mother(int v){
    int k=0;
    for(int i=1;i<=v;i++){
        if(!(vis[i])){
            dfs(i);
            k=i;
        }
    }
    for(int i=1;i<=v;i++) vis[i]=0;
    dfs(k);
    for(int i=1;i<=v;i++){
        if(!vis[i]) return -1;
    }
    return k;
}
int main()
{
    int v, n;
    cin >> v >> n;
    for (int i = 0; i < v; i++)
    {
        int j, k;
        cin >> j >> k;
        ar[j].push_back(k);
    }
    cout<<find_mother(v)<<endl;
}
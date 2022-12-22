#include<bits/stdc++.h>
using namespace std;
void dfs(bool vis[],int v,vector<int> ar[]){
    vis[v]=1;
    cout<<"currnet child is"<<v<<endl;
    for(auto child:ar[v]){
        if(!vis[child])
        dfs(vis,child,ar);
    }
}
int main(){
    int v,g;
    cin>>v>>g;
    vector<int> ar[g];
    bool vis[v];
    memset(vis,0,v);
    for (int i = 0; i < v; i++)
    {
       int a,b;
       cin>>a>>b;
       ar[a].emplace_back(b);
       ar[b].emplace_back(a);
    }
    dfs(vis,1,ar);
}
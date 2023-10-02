#include<bits/stdc++.h>
using namespace std;
int find_parent(int child,vector<int> &parent){
    if(child==parent[child]){
        return child;
    }
    return parent[child] = find_parent(parent[child],parent);
}
void merge_nodes(int u,int v,vector<int> &parent, vector<int> &rank){
    u=find_parent(u,parent);
    v=find_parent(v,parent);
    if(rank[u]>rank[v]){
        parent[v]=u;
    } else if(rank[v]>rank[u]){
        parent[u]=v;
    } else {
        parent[u]=v;
        rank[u]++;
    }
}
long long find_min_price(int ind,int q,int k,int x,int y,vector<pair<int,int>> &parsals,vector<int>&parent,vector<int> &rank,vector<long long> &dp){
    if(ind>=q) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int u=find_parent(parsals[ind].first,parent);
    int v=find_parent(parsals[ind].second,parent);
    long long ans=0;
    if(parsals[ind].first==parsals[ind].second){
        ans=0;
    }
    else if(u==v){
        ans = k + find_min_price(ind+1,q,k,x,y,parsals,parent,rank,dp);
    } else{
        long long non_connect = x + find_min_price(ind+1,q,k,x,y,parsals,parent,rank,dp);
        merge_nodes(u,v,parent,rank);
        long long connect = k + y + find_min_price(ind+1,q,k,x,y,parsals,parent,rank,dp);
        ans = min(connect,non_connect);
    }
    return dp[ind] = ans;
}
long long delivery_price(int n,int q,int k,int x,int y,vector<int> &st,vector<int> &ed,vector<pair<int,int>> &parsals){
    vector<int> parent(n+1,0);
    vector<int> rank(n+1,0);
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<n;i++){
        int u=find_parent(st[i],parent);
        int v=find_parent(ed[i],parent);
        if(u!=v){
            merge_nodes(u,v,parent,rank);
        }
    }
    vector<long long> dp(q+1,-1);
    long long min_price = find_min_price(0,q,k,x,y,parsals,parent,rank,dp);
    return min_price;
}
int main(){
    int n,q,k,x,y;
    cin>>n>>q>>k>>x>>y;
    vector<int> st(n),ed(n);
    for(int i=0;i<n;i++){
        cin>>st[i];
    }
    for(int i=0;i<n;i++){
        cin>>ed[i];
    }
    vector<pair<int,int>> parsals;
    for(int i=0;i<q;i++){
        int a1,a2;
        cin>>a1>>a2;
        parsals.push_back({a1,a2});
    }
    long long price = delivery_price(n,q,k,x,y,st,ed,parsals);
    cout<<price<<endl;
}
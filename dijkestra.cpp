#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges,int source,int destination) {
    //initilazing all required data structure

    //adjency list for storing the pair of {node, distance}
    vector<pair<int,int>> adj[n+1];

    //here we can use set.. used to give the node with shortest distance and traversal of graph store data in the pair of {distance,node}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    //store the distance and initializing with INT_MAX distance
    vector<int> dist(n+1,INT_MAX);

    //storing for parent of each node for minimum distance
    vector<int> parent(n+1);

    //for storing the shotest path
    vector<int> ans;

    //creating adjency list
    for(int i=0;i<m;i++){
        //there is edge for a->b and b->a with weight w
        int a=edges[i][0];
        int b=edges[i][1];
        int w=edges[i][2];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    //initializing parent of each node from itself
    for(int i=1;i<=n;i++) parent[i]=i;

    //insert source node with distance 0
    pq.push({0,source});

    //initialize the distance of source node by 0
    dist[source]=0;

    //BFS traversal the whole graph
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int child=it.first;
            int cur_dis=it.second;
            //updaing values
            if(dis+cur_dis<dist[child]){
                dist[child]=dis+cur_dis;
                parent[child]=node;
                pq.push({dis+cur_dis,child});
            }
        }
    }

    //if path does not exist
    if(dist[destination]==INT_MAX){
        return {-1};
    }

    //here n is destination node
    int node=destination;
    ans.push_back(node);

    //storing the shortest path from source to destination
    while(parent[node]!=node){
        ans.push_back(parent[node]);
        node=parent[node];
    }

    //as path stored reverse so, reverse it again
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){

}
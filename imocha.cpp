//Vipul kumar--Welcome to coding workspace
#include<bits/stdc++.h>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using osetg=tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ul;
#define setbits(x)      __builtin_popcountll(x)
#define flag(fl) fl?cout<<"YES\n":cout<<"NO\n"
#define endl "\n"
#define lp(i,n) for(ll i=0;i<n;i++)
#define lpp(i,n) for(ll i=1;i<n;i++)
#define ff first
#define ss second
#define pi 3.14159265358979323846
#define l_b lower_bound
#define u_b upper_bound
#define sps(x,y)  fixed<<setprecision(y)<<x
#define all(v)  v.begin(),v.end()
const ll M = 1e9+7;
int solve(vector<vector<int>> &vec){
    int n=vec.size();
    int m=vec[0].size()/2;
    vector<vector<pair<int,int>>> mat(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*m;j+=2){
            mat[i].push_back({vec[i][j],vec[i][j+1]});
        }
    }
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    set<pair<int,pair<int,int>>> st;
    st.insert({0,{0,0}});
    dist[0][0]=0;
    int ar[]={-1,1,-1,1};
    int br[]={-1,1,1,-1};
    while (!st.empty())
    {
        auto it=st.begin();
        st.erase(it);
        int dis = it->first;
        int i=it->second.first;
        int j=it->second.second;
        for(int ii=0;ii<4;ii++){
            int x = i+mat[i][j].ff*ar[ii];
            int y =j+mat[i][j].ss*br[ii];
            if(x>=0 and y>=0 and x<n and y<m){
                if(dis+1<dist[x][y]){
                    dist[x][y]=dis+1;
                    st.insert({dis+1,{x,y}});
                }
            }
        }
        for(int ii=0;ii<4;ii++){
            int x = i+mat[i][j].ss*ar[ii];
            int y =j+mat[i][j].ff*br[ii];
            if(x>=0 and y>=0 and x<n and y<m){
                if(dis+1<dist[x][y]){
                    dist[x][y]=dis+1;
                    st.insert({dis+1,{x,y}});
                }
            }
        }
    }
    if(dist[n-1][m-1]==INT_MAX) return -1;
    return dist[n-1][m-1];
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
{

}
return 0;
}
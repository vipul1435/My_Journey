//Vipul kumar--Welcome to coding workspace
#include<bits/stdc++.h>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
typedef long long ll;
typedef unsigned long long ul;
#define setbits(x)      __builtin_popcountll(x)
#define lp(i,n) for(ll i=0;i<n;i++)
#define ff first
#define ss second
#define pi 3.14159265358979323846
#define l_b lower_bound
#define u_b upper_bound
#define sps(x,y)  fixed<<setprecision(y)<<x
#define all(v)  v.begin(),v.end()
const ll M = 1e9+7;
int printRandoms(int lower, int upper)
{
   int k = (rand() %(upper - lower + 1)) + lower;
   return k;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
   vector<char> vec;
   char ch='a';
   lp(i,26){
      vec.push_back(ch);
      ch++;
   }
   // lp(i,26) cout<<vec[i];
   lp(i,200000){
   int k=printRandoms(0,25);
    cout<<vec[k];
   }
}
return 0;
}
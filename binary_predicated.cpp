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
bool check(int ar[],int k,int mid,int n){
    int cnt=0;
    int temp=0;
    lp(i,n){
        temp+=ar[i];
        if(temp>=mid){
            cnt++;
            temp=0;
            if(cnt>=k) return true;
        }
    }
    return false;
}
int solve(int ar[], int n, int ans,int k)
{
    int low=0,high=ans;
    int cnt=0;
    int temp=0;
    int final=0;
    while(low<=high){
        int mid = low+(high-low)/2;
        bool fl =  check(ar,k,mid,n);
        if(fl){
            final=mid;
            low=mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return final;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n>>k;
        int ar[n];
        int ans = 0;
        lp(i, n)
        {
            cin >> ar[i];
            ans += ar[i];
        }
        cout<<solve(ar,n,ans,k)<<endl;
    }
    return 0;
}
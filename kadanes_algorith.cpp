#include<bits/stdc++.h>
using namespace std;
long long max_sum(int ar[],int a){
    int ans =0 ; 
    int maxi = INT_MIN;
    for(int i=0;i<a;i++){
        ans+=ar[i];
        maxi = max(maxi,ans);
        if(ans<0) ans =0;
    }
    return maxi;
}
int main(){
    int a;
    cin>>a;
    int ar[a];
    for(int i=0;i<a;i++) cin>>ar[i];
    long long ans = max_sum(ar,a);
    cout<<ans<<endl;
}
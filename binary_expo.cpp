#include<bits/stdc++.h>
using namespace std;
long long binary_expo(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1){
            ans = (ans * a);
        } 
        b>>=1;
        a = (a*a);
    }
    return ans;
}
long long binary_expo_with_mod(long long a,long long b,long long mod){
    long long ans=1;
    while(b){
        if(b&1){
            ans = (ans%mod * a%mod)%mod;
        } 
        b>>=1;
        a = (a%mod*a%mod)%mod;
    }
    return ans%mod;
}
int main(){
    long long a,b;
    cin>>a>>b;
    cout<<binary_expo(a,b);
}
#include<bits/stdc++.h>
using namespace std;
int gen(int lb,int ub){
    return (rand() % (ub - lb + 1)) + lb;
}
int main(){
    int n;
    cin>>n;
    int x=gen(10,1000);
    cout<<n<<" "<<x<<endl;
    for(int i=1;i<n;i++){
        cout<<gen(1,1000)<<" ";
    }
    cout<<gen(1,100)<<endl;
}
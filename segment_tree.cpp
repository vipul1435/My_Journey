#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,int arr[],int seg[],int orr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr,seg,!orr);
    build(2*ind+2,mid+1,high,arr,seg,!orr);
    if(orr) seg[ind]=seg[2*ind+1] | seg[2*ind+2];
    else seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
}
void update(int ind, int low,int high, int seg[],int pos, int val,int orr){
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(pos<=mid) update(2*ind+1,low,mid,seg,pos,val,!orr);
    else update(2*ind+2,mid+1,high,seg,pos,val,!orr);
    if(orr) seg[ind]=seg[2*ind+1] | seg[2*ind+2];
    else seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
}
int main(){
    int n,q;
    cin>>n>>q;
    int ele = pow(2,n);
    int arr[ele];
    for(int i=0;i<ele;i++) cin>>arr[i];
    int seg[4*ele+1];
    if(n%2==0)
    build(0,0,ele-1,arr,seg,0);
    else 
    build(0,0,ele-1,arr,seg,1);
    while (q--)
    {
        int pos,val;
        cin>>pos>>val;
        pos--;
        if(n%2==0)
        update(0,0,ele-1,seg,pos,val,0);
        else update(0,0,ele-1,seg,pos,val,1);
        cout<<seg[0]<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int partition(int *arr,int low,int high){
    int pivot=arr[high];
    int j=low;
    for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[j],arr[high]);
    return j;

}
void quickSort(int *arr,int low,int high){
    if(high<=low) return;
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
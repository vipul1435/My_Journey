#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int low,int mid,int high){
    int left = mid-low+1;
    int right = high-mid;
    auto *leftArr = new int[left];
    auto *rightArr = new int[right];
    for(int i=0;i<left;i++) leftArr[i] = arr[low+i];
    for(int i=0;i<right;i++) rightArr[i] = arr[mid+1+i];
    int i=0,j=0,k=low;
    while(i<left and j<right){
        if(leftArr[i]<=rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i<left){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<right){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int *arr,int low,int high){
    if(low>=high) return;
    int mid = low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
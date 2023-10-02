#include<bits/stdc++.h>
using namespace std;

// utility fuction to find maximun area in histogram
long long max_area(vector<long long> &vec,int n){
    // to store the index of next and previous smaller element
    vector<int> next(n,-1),prev(n,-1);
    stack<int> st;
    st.push(-1);
    //finding prev smaller element
    for(int i=0;i<n;i++){
        while(st.top()!=-1 and vec[st.top()]>=vec[i]){
            st.pop();
        }
        prev[i]=st.top();
        st.push(i);
    }
    //clearing stack to reuse
    while (!st.empty())
    {
       st.pop();
    }
    st.push(-1);
    //findinng next smaller element
    for(int i=n-1;i>=0;i--){
        while(st.top()!=-1 and vec[st.top()]>=vec[i]){
            st.pop();
        }
        next[i]=st.top();
        st.push(i);
    }

    long long area=0;
    // findind maximum area
    for(int i=0;i<n;i++){
        if(next[i]==-1) next[i]=n;
        int dist = next[i]-prev[i]-1;
        long long ar = vec[i]*dist;
        area=max(area,ar);
    }
    return area;
}

// a better aproach for that using is

long long max_area_mostOptimized(vector<long long> &vec,int n){
    stack<int> st;
    long long area=0;
    for(int i=0;i<=n;i++){
        while (!st.empty() and (i==n || vec[st.top()]>=vec[i]))
        {
            long long height = vec[st.top()];
            st.pop();
            int width;
            if(st.empty()) width=i;
            else width = i-st.top()-1;
            area = max(area , height*width);
        }
        st.push(i);
    }
    return area;
}

int main(){
    int n;
    cin>>n;
    vector<long long> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];

    long long area = max_area_mostOptimized(vec,n);
    cout<<area<<endl;
    return 0;
}
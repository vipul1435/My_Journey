#include<bits/stdc++.h>
using namespace std;
int make_equal(int n,vector<string> &str){
  unordered_map<string,int> freq;
  for(int i=0;i<n;i++){
    freq[str[i]]++;
  }
  int ans=0;
  for(auto it:freq){
    ans=max(ans,it.second);
  }
  freq.clear();
  for(int i=0;i<n;i++){
    set<string> st;
    for(int j=0;j<3;j++){
      string temp = str[i];
      temp.erase(j,1);
      st.insert(temp);
    }
    for(auto it:st){
      freq[it]++;
    }
  }
  for(auto it:freq){
    ans=max(ans,it.second);
  }
  return ans;
}
int main(){
  int n;
  cin>>n;
  vector<string> str(n);
  for(int i=0;i<n;i++){
    cin>>str[i];
  }
  int ans = make_equal(n,str);
  cout<<ans;
}
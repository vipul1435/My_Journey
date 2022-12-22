#include<bits/stdc++.h>
using namespace std;
void build_seg(int ind,int low,int high,string &str, vector<pair<int,pair<int,int>>> &seg){
  if(low==high){
    if(str[low]=='['){
      seg[ind]={1,{0,0}};
    } else {
      seg[ind]={0,{1,0}};
    }
    return;
  }
  int mid=(low+high)/2;
  int left= (2*ind)+1;
  int right=(2*ind)+2;
  build_seg(left,low,mid,str,seg);
  build_seg(right,mid+1,high,str,seg);
  int common= min(seg[left].first,seg[right].second.first);
  int open_brac = seg[left].first+seg[right].first-common;
  int close_brac=seg[left].second.first+seg[right].second.first-common;
  int full_brac=seg[left].second.second+seg[right].second.second+common;
  seg[ind]={open_brac,{close_brac,full_brac}};
  return;
}
pair<int,pair<int,int>> count_balanced(int ind,int low,int high,int l,int r,vector<pair<int,pair<int,int>>> &seg){
  if(l>high or r<low){
    return {0,{0,0}};
  } 
  if(low>=l and high<=r){
    return seg[ind];
  }
  int mid=(low+high)/2;
  int left= (2*ind)+1;
  int right=(2*ind)+2;
  pair<int,pair<int,int>> a,b;
  a=count_balanced(left,low,mid,l,r,seg);
  b=count_balanced(right,mid+1,high,l,r,seg);
  int common= min(a.first,b.second.first);
  int open_brac = a.first+b.first-common;
  int close_brac=a.second.first+b.second.first-common;
  int full_brac=a.second.second+b.second.second+common;
  return {open_brac,{close_brac,full_brac}};
}
string password_generate(string str, vector<pair<int,int>> range){
  int m=str.size();
  vector<pair<int,pair<int,int>>> seg(4*m+5,{0,{0,0}});
  build_seg(0,0,m-1,str,seg);
  string password="";
  for(int i=0;i<range.size();i++){
    int l=range[i].first;
    int r=range[i].second;
    l--;
    r--;
    auto balanced = count_balanced(0,0,m-1,l,r,seg);
    int digi = balanced.second.second;
    string gretest_digit = to_string(digi);
    password+=gretest_digit[gretest_digit.size()-1];
  }
  sort(password.begin(),password.end(),greater<>());
  return password;
}
int main(){
  string str;
  cin>>str;
  int n;
  cin>>n;
  vector<pair<int,int>> range;
  while (n--)
  {
    int l,r;
    cin>>l>>r;
    range.push_back({l,r});
  }
  string password = password_generate(str,range);
  cout<<password<<endl;
  return 0;
}
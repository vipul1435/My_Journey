#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];
    bool containKey(int bit){
        return (links[bit]!=NULL);
    }
    Node* getNode(int bit){
        return links[bit];
    }
    void putNode(int bit, Node* node){
        links[bit]=node;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root= new Node();
    }
    public:
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;--i){
            int bit = (num>>i)&1;
            if(!node->containKey(bit)){
                node->putNode(bit,new Node());
            }
            node = node->getNode(bit);
        }
    }
    public:
    int getMax(int num){
        int ans=0;
        Node* node=root;
        for(int i=31;i>=0;--i){
            int bit= (num>>i)&1;
            if(node->containKey(1-bit)){
                ans|=(1<<i);
                node = node->getNode(1-bit);
            } else {
                node = node->getNode(bit);
            }
        }
        return ans;
    }
};
int maxXor(vector<int> &nums){
    Trie trie;
    for(auto &i:nums) trie.insert(i);
    int ans=0;
    for(auto &i:nums) ans=max(ans,trie.getMax(i));
    for(auto &i:nums) ans=max(ans,i);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin>>vec[i];
        }
        for (int i = 1; i < n; i++)
        {
            vec[i]^=vec[i-1];
        }
        cout<<maxXor(vec)<<endl;
    }
    
}
#include<bits/stdc++.h>
using namespace std;
class segment_tree{
    private:
    vector<int> data;
    int size;

    private:
    void build_segment_tree(int ind,int low,int high,vector<int> &nums){
        if(low==high){
            this->data[ind]=nums[low];
            return;
        }
        int mid = low+(high-low)/2;
        build_segment_tree(2*ind+1,low,mid,nums);
        build_segment_tree(2*ind+2,mid+1,high,nums);
        this->data[ind]=__gcd(this->data[ind*2+1],this->data[ind*2+2]);
    }


    private:
    int range_query(int ind,int low,int high,int left,int right,int &val,int &key){
        if(val>=2) return key;
        if(low>right or high<left){
            return 0;
        }
        if(low>=left and high<=right){
            int d = this->data[ind];
            if(__gcd(d,key)>=key) {
                return d;
            }
            else if(low==high){
                val++;
                if(val>=2) return key;
                return d;
            }
        }
        int mid = low+(high-low)/2;
        int left_data = range_query(2*ind+1,low,mid,left,right,val,key);
        int right_data = range_query(2*ind+2,mid+1,high,left,right,val,key);
        return __gcd(left_data,right_data);
    }

    private:
    void val_update(int ind,int low,int high,int i,int val){
        if(low==high){
            this->data[ind] = val;
            return;
        }
        int mid = low+(high-low)/2;
        if(i<=mid){
            val_update(2*ind+1,low,mid,i,val);
        } else {
            val_update(2*ind+2,mid+1,high,i,val);
        }
        this->data[ind]=__gcd(this->data[ind*2+1],this->data[ind*2+2]);
    }

    public:
    segment_tree(int n){
        this->data.resize(4*n+1,0);
        this->size=n;
    }
    
    public:
    void build(vector<int> &nums){
        build_segment_tree(0,0,this->size-1,nums);
        return;
    }

    public:
    int range(int left,int right,int key){
        int val=0;
        int ans=  range_query(0,0,size-1,left,right,val,key);
        return val;
    }

    public:
    void update(int i,int val){
        val_update(0,0,this->size-1,i,val);
        return;
    }

};
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin>>n;
        segment_tree seg(n);
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        seg.build(vec);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int type;
            cin>>type;
            if(type==1){
                int l,r,v;
                cin>>l>>r>>v;
                int res = seg.range(l-1,r-1,v);
                res<=1?cout<<"YES\n":cout<<"NO\n";
            } else {
                int ind,v;
                cin>>ind>>v;
                seg.update(ind-1,v);
            }
        }
    return 0;
}
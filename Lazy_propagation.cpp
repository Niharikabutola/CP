#include<iostream>
#include<vector>
using namespace std;
class LazyTree{
    vector<int>seg,lazy;

public :
LazyTree(int n){
    seg.resize(4*n);
    lazy.resize(4*n);
}
public:
void build(int ind,int low,int high,vector<int>&arr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
public:
void update(int ind,int low,int high,int l,int r,int val){
    if(lazy[ind]!=0)//lazy present
    {
        seg[ind]+=(high-low+1)*lazy[ind];

    if(low!=high){
        lazy[2*ind+1]+=lazy[ind];
          lazy[2*ind+2]+=lazy[ind];

    }
     lazy[ind]=0;
}
    if(low>r||high<l){
        return;
    }
    if(l<=low&&high<=r){
        seg[ind]+=(high-low+1)*val;
         lazy[2*ind+1]+=val;
          lazy[2*ind+2]+=val;
          return;

    }
    int mid=(low+high)/2;
    update(2*ind+1,low,mid,l,r,val);
     update(2*ind+2,mid+1,high,l,r,val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}
public:
int query(int ind,int low,int high,int l,int r){
     if(lazy[ind]!=0)//lazy present
    {
        seg[ind]+=(high-low+1)*lazy[ind];

    if(low!=high){
        lazy[2*ind+1]+=lazy[ind];
          lazy[2*ind+2]+=lazy[ind];

    }
     lazy[ind]=0;
}
    if(low>r||high<l){
        return 0;
    }
    if(l<=low&&high<=r){
    
          return seg[ind];

    }
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
     int right=query(2*ind+2,mid+1,high,l,r);
    return (left+right);

}

};


int main(){
    int n;
    cin>>n;
    LazyTree t(n);
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    t.build(0,0,n-1,arr);
    int query;
    cin>>query;
    while(query--){
        int type;
        cin>>type;
        if(type==1){
    
    int l,r;
    cin>>l>>r;
    int sum=t.query(0,0,n-1,l,r);
    cout<< sum<<endl;
        }  
        else{

        int l,r,val;
        cin>>l>>r>>val;
   t.update(0,0,n-1,l,r,val);
        }
    }
    
  // t.printTree();
}

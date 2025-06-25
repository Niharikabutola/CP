
#include<bits/stdc++.h>
using namespace std;
class segTree
{
    vector<int>seg;

public:
    segTree(int n)
    {
        seg.resize(4 * n + 1);
    }

void build(int ind ,int low,int high,vector<int>&arr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

}
int query(int ind,int low,int high,int l,int r){
    if(r<low||high<l){//out of range
        return INT_MAX;
    }
   if(l<=low&&high<=r){//completely overlap
        return seg[ind];
    }
        int mid=(low+high)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
    

void  update(int ind,int low,int high,int i,int val){
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid){
        update(2*ind+1,low,mid,i,val);
    }
    else{
         update(2*ind+2,mid+1,high,i,val);
    }
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
};
void solve() {
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    segTree s1(n1);
    s1.build(0, 0, n1 - 1, arr1);

    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    segTree s2(n2);
    s2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;

    vector<int> results;  // 💡 To store outputs

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int mini1 = s1.query(0, 0, n1 - 1, l1, r1);
            int mini2 = s2.query(0, 0, n2 - 1, l2, r2);
            results.push_back(min(mini1, mini2)); // 💡 store result instead of printing
        } else {
            int arrno, i, val;
            cin >> arrno >> i >> val;
            if (arrno == 1) {
                s1.update(0, 0, n1 - 1, i, val);
            
            } else {
                s2.update(0, 0, n2 - 1, i, val);
                
            }
        }
    }

    // ✅ Print all answers at the end
    for (int ans : results) {
        cout << ans << endl;
    }
}

int main(){
    solve();
    return 0;
}
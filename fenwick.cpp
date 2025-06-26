#include<iostream>
#include<vector>
using namespace std;
class fenwick{
    public:
    vector<int>fen;
    public:
    fenwick(int n){
        fen.resize(n+1,0);
    }
public:
void update(int i,int add){
    int N=fen.size();
    while(i<N)
    {
        fen[i]+=add;
        i+=(i&(-i));
    }
}
public:
int sum(int i){
    int s=0;
    while(i>0){
    s+=fen[i];
    i=i-(i&(-i));}
    return s;

}
public:
int rangesum(int l,int r){
    return sum(r)-sum(l-1);
}
};
int main(){
    int n;
    cin>>n;
    fenwick f(n);
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
         f.update(i,arr[i]);
    }
   
    int l,r;
    cin>>l>>r;
      
   cout<<"sum of 1 to"<<r<<"=" <<f.sum(r)<<endl;
    cout<<"range sum from"<<l<<"to"<<r<<"="<<f.rangesum(l,r)<<endl;
}
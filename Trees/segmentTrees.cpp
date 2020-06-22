#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(vector<int>& a, vector<int>& st, int start, int end, int node){
    if(start==end){
        st[node]=a[start];
        return;
    }

    int mid = (start+end)/2;
    buildSegmentTree(a, st, start, mid, 2*node+1);
    buildSegmentTree(a, st, mid+1, end, 2*node+2);

    st[node] = st[2*node+1] + st[2*node+2];
}

int main(){
    int n=10;
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    
    int h = floor(log2(2*n-1))+1;
    int len = pow(2,h)-1;
    vector<int> st(len, -1);

    buildSegmentTree(a,st,0,n-1,0);
    
    for(int i=0; i<len; i++){
        cout<< i<<" : "<<st[i]<<endl;
    }
    cout<<"\n\n";
    return 0;
}
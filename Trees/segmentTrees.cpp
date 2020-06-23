#include<bits/stdc++.h>
using namespace std;

// CREATE
vector<int> createSegmentTree(vector<int>&,int);
void buildSegmentTree(vector<int>&, vector<int>&, int, int, int);

// GET SUM
int getSum(vector<int>&, int, int, int);
int getSumRange(vector<int>&, int , int, int, int, int);

// UPDATE
void update(vector<int>&, vector<int>&, int, int, int);
void updateValue(vector<int>&, int, int, int, int, int);

// PRINT
void printTree(vector<int>, int);

int main(){
    int n=10;
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    
    vector<int> st = createSegmentTree(a,n);
    
    printTree(st,n);

    cout<<"sum = "<<getSum(st, n, 7, 9)<<endl;

    update(a, st, 15, 4, n);
    
    cout<<"updated\n";
    printTree(st,n);

    return 0;
}



// CREATE SEGEMENT TREE

vector<int> createSegmentTree(vector<int>& a, int n){
    int h = floor(log2(2*n-1))+1;
    int len = pow(2,h)-1;
    vector<int> st(len, -1);

    buildSegmentTree(a, st, 0, n-1, 0);

    return st;
}

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



// GET SUM FOR A RANGE

int getSum(vector<int>& st, int n, int rstart, int rend){
    if(rstart>rend || rstart<0 || rend>n-1){
        return -1;
    }

    return getSumRange(st,0,n-1,rstart, rend, 0);
}

int getSumRange(vector<int>& st, int start, int end, int rstart, int rend, int node){
    if(rstart<=start && rend>=end){
        return st[node];
    }

    if(rstart>end || rend<start){
        return 0;
    }

    int mid = (start+end)/2;

    return getSumRange(st, start, mid, rstart, rend, 2*node+1) + getSumRange(st, mid+1, end, rstart, rend, 2*node+2);
}



// UPDATE A VALUE IN THE ORIGINAL ARRAY AND SEGMENT TREE

void update(vector<int>& a, vector<int>& st, int value, int index, int n){
    int diff = value - a[index];
    a[index] = value;

    updateValue(st, diff, index, 0, n-1, 0);
}

void updateValue(vector<int>& st, int diff, int index, int start, int end, int node){
    if(index<start || index>end){
        return;
    }

    st[node]+=diff;

    if(start!=end){
        int mid = (start+end)/2;
        updateValue(st, diff, index, start, mid, 2*node+1);
        updateValue(st, diff, index, mid+1, end, 2*node+2);
    }
}



// PRINT SEGMENT TREE

void printTree(vector<int> st, int n){
    int h = floor(log2(2*n-1))+1;
    int len = pow(2,h)-1;

    for(int i=0; i<len; i++){
        cout<<st[i]<<"  ";
    }
    cout<<endl;
}
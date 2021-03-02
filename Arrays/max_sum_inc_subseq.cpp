// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
#include<bits/stdc++.h>
using namespace std;

int getMaxSumSubSeq(vector<int> a, int sum, int idx, int prev){
    int temp1,temp2;

    if(idx==a.size()){
        return sum;
    }

    temp1 = getMaxSumSubSeq(a,sum,idx+1,prev);

    if(a[idx]>=a[prev]){
        sum +=a[idx];
        temp2 = getMaxSumSubSeq(a,sum,idx+1,idx);       
    }

    

    return 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    vector<int> a;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>temp;
        a.push_back(temp);
    }

    cout<<getMaxSumSubSeq(a,0,0,0);

    return 0;
}
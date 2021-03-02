// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
#include<bits/stdc++.h>
using namespace std;

pair<int,int> getSumpair(int n, int reqsum, vector<int> a){
    int last = n-1;
    int p = 0;

    while(p<last){
        if(a[last]+a[p] == reqsum){
            return pair<int,int>(a[p],a[last]);
        }
        if(a[last]+a[p] < reqsum){
            p++;
        }
        if(a[last]+a[p] > reqsum){
            last--;
        }
    }

    return pair<int,int>(-1,-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, reqsum, pivot=0, temp;
    cin>>n>>reqsum;

    vector<int> a(n);
    cin>>a[0];
    for(int i=1; i<n; i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            pivot = i;
        }
    }

    for(int i=0; i<pivot; i++){
        temp = a[0];
        a.erase(a.begin());
        a.push_back(temp);
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    pair<int,int> sumpair = getSumpair(n, reqsum, a);
    cout<<endl<<sumpair.first<<","<<sumpair.second<<endl;

    return 0;
}
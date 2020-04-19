#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int a[n] = {34,12,2,56,12};
    // assending order
    for(int i=1; i<n; ++i){
        int num = a[i];
        int j=i-1;
        while(j>=0 && a[j]>num){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = num;
    }
cout<<endl;
    for(int i=0; i<n; ++i)
        cout<<a[i]<<" ";
    return 0;   
}
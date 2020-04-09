#include<bits/stdc++.h>
using namespace std;

void mergeSort(int*,int, int, int*);
void merge(int*, int, int, int, int*);

int main(){
    int n = 8;
    int a[n] = {0,2,7,2,4,1,9,0}, b[n];

    mergeSort(a, 0, n-1, b);
  
    for(int i=0; i<n; ++i)
        cout<<a[i]<<endl;

    return 0;
}

void mergeSort(int a[], int low, int high, int b[]){

    if(high<=low)
        return;
    
    int mid = (low+high)/2;

    mergeSort(a, low, mid, b);
    mergeSort(a, mid+1, high, b);

    merge(a, low, mid, high, b);
}

void merge(int a[], int low, int mid, int high, int b[]){
    int i = low, j = mid+1, count = low;

    while(i<=mid && j<=high){
        if(a[i]<= a[j])
            b[count++] = a[i++];
        else
            b[count++] = a[j++];
    }

    while(i<=mid)
        b[count++] = a[i++]; 
    
    while(j<=high)
        b[count++] = a[j++];

    for(int k = low; k<=high; k++)
        a[k] = b[k];
}
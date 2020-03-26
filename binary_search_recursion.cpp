#include<bits/stdc++.h>
using namespace std;

int binarySearch(int*, int, int, int);

int main(){
    int n = 5;
    int a[n] = {23, 24, 83, 103, 123}; // array should be sorted
    int searchTerm = 113;
    int start = 0, end = n-1;
    int pos = binarySearch(a,start,end,searchTerm);
    cout<<pos;
    return 0;
}

int binarySearch(int *a, int start, int end, int searchTerm){
    if(start<=end){
        int middle = (start+end)/2;
        if(a[middle]==searchTerm)
            return middle+1;
        else if(a[middle]<searchTerm)
            return binarySearch(a, middle+1, end, searchTerm);
        else
            return binarySearch(a, start, middle-1, searchTerm);
    }
    else
    {
        return -1;
    }
    
    
}
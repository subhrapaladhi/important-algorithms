#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int a[n] = {23, 24, 83, 103, 123}; // array should be sorted
    int searchTerm = 123;
    int start=0, end = n-1, middle;

    while(start<=end){
        middle = (start+end)/2; 
        if(a[middle]==searchTerm){
            cout<<"position of "<< searchTerm<<" = "<<middle+1;
            break;
        }
        else if(a[middle]<searchTerm)
            start = middle+1;
        else
            end = middle-1;
    }
    if(start>end)
        cout<<"not found";
    return 0;
}
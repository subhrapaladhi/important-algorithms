#include<bits/stdc++.h>
using namespace std;

int printfibonacci(int n, int *values){
    if(values[n]!=0)
        return values[n];
    if(n==1 || n==2){
        values[n] = 1;
        return values[n];
    }
    else{
        values[n] = printfibonacci(n-1, values)+printfibonacci(n-2, values);
        return values[n];
    }
}


int main(){
    // get first n fibonacci numbers
    int n = 7;
    int values[n+1] = {0};

    printfibonacci(n, values);

    for(int i=1; i<=n; i++)
        cout<<values[i]<<endl;

    return 0;
}
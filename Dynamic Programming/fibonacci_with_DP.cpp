#include<bits/stdc++.h>
using namespace std;

vector<int> fib;

int Getfib(int n){
    if(fib[n] != -1) return fib[n];
    if(n<=1) return fib[n] = n;
    return fib[n] = Getfib(n-1) + Getfib(n-2);
}


int main(){
    int n =9;
    fib = vector<int>(n+1,-1);
    cout<<Getfib(n);
    return 0;
}
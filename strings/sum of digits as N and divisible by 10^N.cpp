// https://www.geeksforgeeks.org/smallest-number-sum-digits-n-divisible-10n/
#include<bits/stdc++.h>
using namespace std;

string calcnum(int n){
    string s;
    if(n==0){
        return "0";
    }

    if(n%9!=0){
        s+=to_string(n%9);
    }

    for(int i=0; i<(n/9); ++i){
        s+="9";
    }
    for(int i=0; i<n; i++){
        s+="0";
    }

    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    string s = calcnum(n);
    cout<<s;
    return 0;
}
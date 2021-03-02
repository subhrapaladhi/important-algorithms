// https://leetcode.com/problems/count-sorted-vowel-strings/
#include<bits/stdc++.h>
using namespace std;

int countVowelStrings(int n){
    vector<int> a(5,1);

    for(int k=0; k<n-1; k++){
        for(int i=0; i<5; i++){
            for(int j=i+1; j<5; j++){
                a[i] += a[j];
            }
        }
    }

    return a[0]+a[1]+a[2]+a[3]+a[4];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<countVowelStrings(10);
    return 0;
}
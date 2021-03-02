// https://www.geeksforgeeks.org/number-subsequences-string-divisible-n/
#include<bits/stdc++.h>
using namespace std;

int countsubseq(string s, int n, int idx, int rem){
    // when index is equal to last index of string
    if(idx==s.length()){
        // if remendier is 0 then count it otherwise dont count it(return 1 else 0)
        return (rem==0?1:0);
    }
    int count = 0;

    // dont include the current element
    count+=countsubseq(s,n,idx+1,rem);
    
    int remidx = ((rem*10)+(s[idx]-'0'))%n;
    
    // include the current element
    count+=countsubseq(s,n,idx+1,remidx);
    
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n;
    cin>>s>>n;

    // 1 is being substracted to remove the case where nothing is being included
    int count = countsubseq(s,n,0,0)-1;
    cout<<count<<endl;
    return 0;
}
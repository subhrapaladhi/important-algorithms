// https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/
#include<bits/stdc++.h>
using namespace std;

int countsubseq(string s, string t, string sub, int idx, unordered_map<string,int> m){
    string key = sub + to_string(idx);
    if(m.find(key)!=m.end()){
        return m.find(key)->second;
    }

    int count = 0;
    if(sub==t){
        return 1;
    }

    if(idx==s.length()){
        return 0;
    }

    count+=countsubseq(s,t,sub,idx+1,m);
    m[key] = count;

    sub+=s[idx];
    key = sub + to_string(idx);
    
    count+=countsubseq(s,t,sub,idx+1,m);
    m[key] = count;
    
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t, sub="";
    cin>>s>>t;

    unordered_map<string,int> m;

    cout<<countsubseq(s,t,sub,0,m);

    return 0;
}
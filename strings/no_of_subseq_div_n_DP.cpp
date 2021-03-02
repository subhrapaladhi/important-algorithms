// https://www.geeksforgeeks.org/number-subsequences-string-divisible-n/
#include<bits/stdc++.h>
using namespace std;

int getCount(string s, int n, unordered_map<string,int> m, int idx, int rem){
    // pair<int,int> key = pair<int,int>(idx,rem);
    string key = to_string(idx) + to_string(rem);
    if(m.find(key)!=m.end()){
        return m.find(key)->second;
    }
    
    int count = 0;

    if(idx==s.length()){
        count = rem==0?1:0;
        m.insert(pair<string,int>(key,count));
        return count;
    }

    count+=getCount(s, n, m, idx+1, rem);
    m.insert(pair<string,int>(key,count));

    int remidx = (rem*10 + (s[idx]-'0'))%n;
    
    count+=getCount(s, n, m, idx+1, remidx);
    key = to_string(idx) + to_string(remidx);
    
    m.insert(pair<string,int>(key,count));

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n;
    cin>>s>>n;
    
    unordered_map<string,int> m;
    int rem = 0, idx = 0;
    int count = getCount(s, n, m, idx, rem)-1;

    cout<<count<<endl;

    return 0;
}
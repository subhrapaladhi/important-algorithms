// https://www.hackerrank.com/challenges/balanced-brackets/problem
#include<bits/stdc++.h>
using namespace std;

string isBalanced(string);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    string s;
    while(t--){
        cin>>s;
        cout<<isBalanced(s)<<endl;
    }

    return 0;
}


string isBalanced(string s){
    stack<char> stk;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            stk.push(s[i]);

        else if(!stk.empty()){
            if(s[i]==')' && stk.top()=='('){
                stk.pop();
            } 
            else if(s[i]==']' && stk.top()=='['){
                stk.pop();
            } 
            else if(s[i]=='}' && stk.top()=='{'){
                stk.pop();
            } 
            else {
                return "NO";
            }
        }

        else{
            return "NO";
        }
    }

    if(stk.empty()){
        return "YES";
    }
    return "NO";
}
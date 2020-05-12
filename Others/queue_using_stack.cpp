#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q, x;
    int type;
    stack<long long> s1, s2;
    cin>>n;

    while(n--){
        cin>>type;

        if(type==1){
            cin>>x;
            s1.push(x);
        } else {
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            if(type==2)
                s2.pop();
            if(type==3)
                cout<<s2.top()<<endl;
        }
    }

    return 0;
}
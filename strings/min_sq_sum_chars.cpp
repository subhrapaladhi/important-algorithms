// https://www.geeksforgeeks.org/minimum-sum-squares-characters-counts-given-string-removing-k-characters/
#include<bits/stdc++.h>
using namespace std;

int getSum(priority_queue<int> pq, int k){
    int sum = 0;

    while(true){
        int temp1 = pq.top();
        pq.pop();
        if(temp1>k){
            sum = pow((temp1-k),2);
            break;
        }else{
            k = k-temp1;
        }
    }

    while(!pq.empty()){
        sum+=pow(pq.top(),2);
        pq.pop();
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin>>input;
    
    map<char,int> m;

    for(int i=0; i<input.length(); i++){
        if(m.find(input[i])!=m.end()){
            m.find(input[i])->second++;
        } else {
            m.insert(pair<char,int>(input[i],1));
        }
    }

    priority_queue<int> pq;

    int k;
    cin>>k;

    map<char,int>::iterator itr;
    for(itr = m.begin(); itr!=m.end(); itr++){
        pq.push(itr->second);
    }

    int sum = getSum(pq,k);
    cout<<sum<<endl;
    return 0;
}
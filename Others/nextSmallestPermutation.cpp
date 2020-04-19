#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"enter s: ";
    cin>>s;
    int l = s.length();
    int pivot=-1;

    for(int i=l-1; i>0; --i){
        if(s[i]<s[i-1]){
            pivot = i-1;
            break;
        }
    }

    if(pivot!=-1){
        for(int i=l-1; i>pivot; --i){
            // finding the just smaller element in the suffix
            if(s[i]<s[pivot]){
                char temp = s[i];
                s[i] = s[pivot];
                s[pivot] = temp;
                break;
            }   
        }

        reverse(s.begin()+pivot+1,s.end());
        cout<<"next smallest permutation: "<<s<<endl;
    }
    else{
        cout<<"already the smallest permutation"<<endl;
    }
    
    return 0;
}
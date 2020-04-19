#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"enter s: ";
    cin>>s;
    int l = s.length();
    int pivot=-1;
    for(int i=l-1; i>0; --i){   // loop till (from back) till the non-decreasing order is maintained
        if(s[i]>s[i-1]){        // pivot: the number greater that it's next number
            pivot = i-1;
            break;
        }
    }
    if(pivot!=-1){  
        for(int i=l-1; i>pivot; --i){
            /*  exchanging the pivot and smallest element 
                larger than our pivot element present at the 
                hightest possible index of our suffix string    */

           if(s[pivot]<s[i]){       // exchaning element at pivot and i
               char temp = s[i];
               s[i] = s[pivot];
               s[pivot] = temp;
               break;
           }
        }
        // reverse the elements afer the pivot element to get 
        // the lowest possible combination for the suffix part
        reverse(s.begin()+pivot+1, s.end());
        cout<<"next largest permutation: "<< s<<endl;
    }

    else{
        cout<<"already largest permutation"<<endl;
    }

}
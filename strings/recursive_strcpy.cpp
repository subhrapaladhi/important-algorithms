// https://www.geeksforgeeks.org/function-copy-char-iterative-recursive/
#include<bits/stdc++.h>
using namespace std;

void recursive_strcpy(char *s1, char *s2, int i){
    // cout<<"i = "<<i<<" | s1 ="<<s1<<" | s2 ="<<s2<<endl;
    
    s2[i] = s1[i];

    if(s1[i]=='\0'){
        return;
    }
    
    recursive_strcpy(s1,s2,i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s1[100]="geeksforgeeks";
    // cin>>s1;
    char s2[100];
    recursive_strcpy(s1,s2,0);
    cout<<s2;

    return 0;
}
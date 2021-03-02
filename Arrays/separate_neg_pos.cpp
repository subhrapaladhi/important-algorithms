// Move all negative numbers to beginning and positive to end with constant extra space
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    cin>>n;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int left=0, right=n-1;
    // left side is positive
    // right side is negative
    while(left<right){
        if(a[left]>=0){
            left++;
        } else {
            while(left<right && a[right]<0){
                right--;
            }
            if(left==right){
                break;
            }
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
            left++;
        }

        if(a[right]<0){
            right--;
        } else {
            while(left<right && a[left]>0){
                left++;
            }
            if(left==right){
                break;
            }
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
            right++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;
    return 0;
}
// n-number of elements in array. d-required number of rotations
// get the gcd of n & d. loop through the array for n/gcd times with increments of gcd and keep shifting them.

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int ans;
    if(a<b){
        for(int i=a; i>=1; i--){
            if((a%i==0) && (b%i==0)){
                return i;
            }
        }
    } else {
        for(int i=b; i>=1; i--){
            if((a%i==0) && (b%i==0)){
                return i;
            }
        }
    }
    return -1;
}

void juggle(int *arr, int n, int d, int GCD){
    int i,j,k;
    for(i=0; i<GCD; i++){
        int temp = arr[i];
        j=i;
        while(true){
            k = (j+d)%n;
            if(k==i){
                break;
            }
            arr[j] = arr[k];
            j=k;
        }
        arr[j] = temp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,d;
    cin>>n>>d;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int GCD = gcd(n,d);
    cout<<"GCD = "<<GCD<<endl;
    d = d%n;
    juggle(arr,n,d,GCD); 

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}
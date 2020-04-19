#include<bits/stdc++.h>
using namespace std;

void quickSort(int*, int, int);
void findPivot(int*, int, int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 7;
    int a[n] = {4,2,0,1,8,4,2};

    quickSort(a, 0, n-1);

    for(int i=0; i<n; ++i)
        cout<<a[i]<<endl;

    return 0;
}

void quickSort(int *a, int start, int end){
    if(start<end){
        int left = start, right = end;
        int pivot = start;

        while(left<right){
            while(left<right && a[left]<=a[pivot])
                left++;
            while(a[right]>a[pivot])
                right--;

            if(left<right){
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
            }
        }
        int temp = a[pivot];
        a[pivot] = a[right];
        a[right] = temp;

        quickSort(a, start, right-1);
        quickSort(a, right+1, end);
    }
}
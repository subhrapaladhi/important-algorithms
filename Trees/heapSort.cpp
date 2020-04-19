#include<bits/stdc++.h>
using namespace std;

void heapify(int*, int, int);
void heapsort(int*, int);

int main(){
    
    int a[9] = {4,2,6,4,9,4,6,10,4};
    int n = 9;
    heapsort(a, n);
    for(int i=0; i<n; ++i)
        cout<<a[i]<<endl;
    return 0;
}

void heapsort(int *a, int n){
    // convert the array to heap before sorting
    for(int i = n/2 -1; i>=0; --i)  // n/2 -1 is the parent of the last element in the BT
        heapify(a, n, i);
    
    /*  Now we will swap the largest element(top of max-heap) with the last elemenet 
        present at the end of arr and reduce the size of array with each swap, 
        hense the array will get sorted in assending order */
    for(int i = n-1; i>=0; --i){
        swap(a[0], a[i]);
        // heapify after each swap so that the largest element in the new array moves to top
        heapify(a, i, 0);       
    }
}

void heapify(int *a, int n, int i){
    int largest = i, leftChild = 2*i+1, rightChild = 2*i+2;

    if(leftChild<n && a[largest]<a[leftChild])
        largest = leftChild;
    if(rightChild<n && a[largest]<a[rightChild])
        largest = rightChild;

    /*  if the root element is not the largest then swap with largest and 
        heapify the sub-tree(the one which had largest as it's root)   */
    if(largest!=i){             
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
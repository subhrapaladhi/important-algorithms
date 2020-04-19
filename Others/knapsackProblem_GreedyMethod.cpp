#include<bits/stdc++.h>
using namespace std;

int largest(float*, int);

int main(){
    int n=5;
    float weights[n] = {4,2,7,8,5}, cost[n] = {7,3,9,5,2};
    float costPerKg[n];
    float knapsack_size = 20, totalCost = 0;
    for(int i=0; i<n; i++)
        costPerKg[i] = cost[i]/weights[i];
    int counter = 0;
    while(knapsack_size>0 && counter<n){
        counter++;
        int i = largest(costPerKg,n);
        int weight = knapsack_size - weights[i]>=0? weights[i]: knapsack_size;
        knapsack_size-=weight;
        totalCost+=weight*costPerKg[i];
        costPerKg[i]*=-1;
    }

    cout<<"totalCost = "<<totalCost<<endl;

    return 0;
}

int largest(float *a, int n){
    float max=0;
    int l_index;
    for(int i=0; i<n; i++){
        if(max<a[i]){
            max = a[i];
            l_index = i;
        }
    }

    return l_index;
}
// https://leetcode.com/problems/min-cost-climbing-stairs/
#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> cost){
    int n = cost.size();
    vector<int> a(n);
    a[0] = cost[0], a[1] = cost[1];

    for(int i=2; i<n; i++){
        a[i] = cost[i] + min(a[i-1],a[i-2]);
    }

    return min(a[n-1],a[n-2]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});

    return 0;
}
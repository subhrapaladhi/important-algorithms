// https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> nums){
    int maxSum=INT_MIN, sum=0;
    for(int i=0; i<nums.size(); i++){
        if(sum<0) sum=0;
        sum += nums[i];
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
    return 0;
}
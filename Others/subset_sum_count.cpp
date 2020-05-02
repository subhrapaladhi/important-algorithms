#include<bits/stdc++.h>
using namespace std;

int get_no_subsets(int *a, int sum, int i, map<string, int> mem){
    /*
        creating key to search or find in map
        key = index(i):sum values(sum)
        value = number of subsets from 0 to i which has sum equal to sum
    */
    string key = to_string(i)+":"+to_string(sum);   

    if(mem.find(key)!=mem.end()) //if entry not found for the key then mem.find(key) returns mem.end()
        return mem[key];

    if(sum==0)                  // an empty subset has sum=0 so we return 1(empty subset)
        return 1;   

    if(i<0)
        return 0;
    
    int val;
    if(a[i]>sum)                // if a[i]>sum then it is not going to be a part of sum so call ([0... i-1], sum)
        val = get_no_subsets(a, sum, i-1, mem);
    /*
        a[i]<=sum so two possibilities: 
        1. no of subsets which inclues a[i]: call([0...i-1], sum-a[i])
        2. no of subsets which does not include a[i]: call([0...i-1], sum)
        total = (1)+(2)
    */
    else 
        val = get_no_subsets(a, sum-a[i], i-1, mem)
                + get_no_subsets(a, sum, i-1, mem);
        
    // store the no of subsets whose sum is equal to sum in map
    mem.insert(pair<string,int>(key, val));

    return val;
}

int main(){
    int n=6;
    int a[n] = {2, 4, 6, 10, -1, -3};
    int sum = 9;
    map<string, int> mem;
    cout<< get_no_subsets(a, sum, n-1, mem)<<endl;

    return 0;
}
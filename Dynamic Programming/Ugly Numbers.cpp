// geeksforgeeks.org/ugly-numbers/
#include<bits/stdc++.h>
using namespace std;

// DP approach
int solveDP(int n){
    vector<int> dp(n);
    dp[0] = 1;
    int i2,i3,i5, next_ugly_num;
    i2=i3=i5=0;
    for(int i=1; i<n; i++){
        next_ugly_num = min(dp[i2]*2, dp[i3]*3, dp[i5]*5);
        dp[i] = next_ugly_num;

        if(dp[i2]*2 == next_ugly_num) i2++;
        if(dp[i3]*3 == next_ugly_num) i3++;
        if(dp[i5]*5 == next_ugly_num) i5++;
    }

    return dp[n-1];
}

// Set approach
int solveSET(int n){
    set<int> s;
    s.insert(1);
    int x;
    for(int i=1; i<n; i++){
        auto it = s.begin();
        x = *it;
        s.erase(it);

        s.insert(x*2);
        s.insert(x*3);
        s.insert(x*5);
    }

    return *s.begin();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
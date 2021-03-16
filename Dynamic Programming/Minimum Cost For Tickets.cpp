#include<bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs){
    int n = days.size(), d7, d30;
    vector<int> dp(n+1,0);

    for(int i=n-1; i>=0; i--){
        d7 = d30 = i;
        while(d7<n && days[d7]<days[i]+7) d7++;
        while(d30<n && days[d30]<days[i]+30) d30++;
        dp[i] = min({costs[0]+dp[i+1], costs[1]+dp[d7], costs[2]+dp[d30]});
    }

    return dp[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
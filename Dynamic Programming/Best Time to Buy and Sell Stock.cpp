#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices){
    int maxprofit=0, mincost=prices[0];

    for(int i=1; i<prices.size(); i++){
        maxprofit = max(maxprofit, prices[i]-mincost);
        mincost = min(mincost,prices[i]);
    }

    return maxprofit;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<maxProfit({7,1,5,3,6,4});

    return 0;
}
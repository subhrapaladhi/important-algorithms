#include<bits/stdc++.h>
using namespace std;

int minelement(int*, int);

int main(){
    vector<int> income = {5,4,3,2,1}, timelimit = {3,5,2,3,1};
    
    int n = *max_element(timelimit.begin(), timelimit.end());
    int timeslots[n] = {0};    // slots: 0-1 1-2  2-3 ... 5-6

    int i=0, jobquelen = 5, totincome = 0, j;

    auto minelement = [](int *arr, int l){ return *min_element(arr,arr+l);};

    while(minelement(timeslots,n) == 0 && i<jobquelen){
        int j=timelimit[i];
        while(j>=0){
            if(timeslots[j]==0){
                timeslots[j] = income[i];
                totincome+=income[i];
                break;
            }
            j--;
        }
        i++;
    }
    cout<<"total income = "<<totincome<<endl;
    return 0;
}
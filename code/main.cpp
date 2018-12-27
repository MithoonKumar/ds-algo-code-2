#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<list>
#include<set>
#include<unordered_map>
#include<sstream>
#include<limits.h>
#include<stdio.h>
using namespace std;
#define faster  ios_base::sync_with_stdio(false); cin.tie(NULL)

int matrix[100][100];

int kadane(vector<int>vec) {
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<vec.size(); i++) {
        if (sum+vec[i]>=0) {
            sum = sum + vec[i];
        } else {
            sum = 0;
        }
        maxSum = sum>maxSum?sum:maxSum;
    }
    return maxSum;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int r, c;
    cin>>r>>c;
    for(int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            cin>>matrix[i][j];
        }
    }
    
    int maxVal = INT_MIN;
    for (int m=1; m<=c; m++) {
        for (int n=1; n<=c; n++) {
            vector<int>tempVec;
            for(int i=1; i<=n; i++) {
                int sum = 0;
                for (int j=m; j<=n; j++){
                    sum+=matrix[i][j];
                }
                tempVec.push_back(sum);
            }
            int returnedVal = kadane(tempVec);
            maxVal = maxVal<returnedVal?returnedVal:maxVal;
        }
    }
    
    cout<<maxVal<<endl;
    
    
    return 0;
}


    

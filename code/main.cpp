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

bool dpCalculate(int S[], int n, int sum) {
    bool arr[n+1][sum+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(j==0) {
                arr[i][j] = true;
            } else {
                arr[i][j]=false;
            }
        }
    }
    for(int i=0; i<=n; i++) {
        cout<<S[i]<<" ";
    }
    cout<<endl;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            bool left = arr[i-1][j];
            bool right = j-S[i-1]>=0 ? arr[i-1][j-S[i-1]]: false;
            arr[i][j] = left || right;
        }
    }
    
//    if (sum == 0) {
//        return true;
//    }
//    if (sum<=0) {
//        return false;
//    }
//    if (n==0) {
//        return false;
//    }
//    return dpCalculate(S, n-1, sum) || dpCalculate(S, n-1, sum-S[n-1]);
    return arr[n][sum];
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n, sum;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cin>>sum;
    cout<<dpCalculate(arr, n, sum)<<endl;
    return 0;
}

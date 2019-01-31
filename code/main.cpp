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


bool checkIfHalfSum(int * arr, int n, int halfSum) {
    bool dpArr[halfSum+1][n];
    for (int j=0; j<n; j++) {
        dpArr[0][j] = true;
    }
    
    for(int i=1; i<=halfSum; i++) {
        if (i == arr[0]) {
            dpArr[i][0] = true;
        } else {
            dpArr[i][0] = false;
        }
    }
    
    for (int i=1; i<=halfSum; i++) {
        for (int j=1; j<n; j++) {
            int first = dpArr[i][j-1];
            int second = i - arr[j] >=0 ? dpArr[i - arr[j]][j-1] : false;
            dpArr[i][j] = first ||second;
        }
    }
    return dpArr[halfSum][n-1];
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        int sum = 0;
        for (int i=0; i<n; i++) {
            cin>>arr[i];
            sum+=arr[i];
        }
        if ((sum%2) != 0) {
            cout<<"NO"<<endl;
        } else {
            int halfSum = sum/2;
            int ans = checkIfHalfSum(arr, n-1, halfSum);
            if (ans) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
        
    }
    
    return 0;
}




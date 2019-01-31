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


bool checkIfHalfSum(long long * arr, int index, long long halfSum) {
    if (halfSum == 0) {
        return true;
    }
    if (halfSum < 0) {
        return false;
    }
    if (index < 0) {
        return false;
    }
    return checkIfHalfSum(arr, index-1, halfSum-arr[index]) || checkIfHalfSum(arr, index-1, halfSum);
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long arr[n];
        long long sum = 0;
        for (int i=0; i<n; i++) {
            cin>>arr[i];
            sum+=arr[i];
        }
        if ((sum%2) != 0) {
            cout<<0<<endl;
        } else {
            long long halfSum = sum/2;
            cout<<checkIfHalfSum(arr, n-1, halfSum);
        }
        
    }
    
    return 0;
}



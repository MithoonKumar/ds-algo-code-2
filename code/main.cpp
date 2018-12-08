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
int globalArr [100][100];

int dpCalculate(int S[], int m, int n) {
    if (m<=0 && n>0){
        return 0;
    }
    if (n<0) {
        return 0;
    }
    int first = globalArr[m-1][n]>0?globalArr[m-1][n]:dpCalculate(S, m-1, n);
    globalArr[m-1][n] = first;
    int second = globalArr[m][n-S[m-1]]>0?globalArr[m][n-S[m-1]]:dpCalculate(S, m, n-S[m-1]);
    globalArr[m][n-S[m-1]] = second;
    return first + second;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n, k;
    cin>>n>>k;
    int arr[k];
    for (int i=0; i<k; i++) {
        cin>>arr[i];
    }
    for (int i=0; i<=k; i++) {
        for(int j=0; j<=n; j++) {
            globalArr[i][j] = -1;
            if (j==0) {
                globalArr[i][j] = 1;
            }
        }
    }
    cout<<dpCalculate(arr, k, n);
    
    return 0;
}

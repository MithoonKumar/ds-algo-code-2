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

int dpCalculate(int n, int k) {
    int arr[n+1][k+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(j,k); j++) {
            if (j == 0 ) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j] + (j* arr[i-1][j-1]);
            }
            arr[i][j+1] = 0;
        }
    }
    return arr[n][k];
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n,k;
    n = 10;
    k = 2;
    cout<<dpCalculate(n, k);
    return 0;
}

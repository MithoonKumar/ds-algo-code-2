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

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n,k;
    cin>>n>>k;
    int matrix[n+1][n+1];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>matrix[i][j];
        }
    }
    int verticalSumMatrix[n+1][n+1];
    for(int j=1; j<=n; j++) {
        int tempSum = 0;
        for (int i=1;i<=k; i++) {
            tempSum+=matrix[i][j];
        }
        verticalSumMatrix[1][j] = tempSum;
    }
    
    for(int j=1; j<=n; j++) {
        for(int i=2; i<=n-k+1; i++) {
            verticalSumMatrix[i][j] = verticalSumMatrix[i-1][j] + matrix[i][j] - matrix[i-k+1][j];
        }
    }
    
    int answer = INT_MIN;
    int x = -1, y = -1;
    for(int i=1; i<=n-k+1; i++) {
        int tempSum = 0;
        for(int l = 1; l<=k; l++) {
            tempSum+=verticalSumMatrix[i][l];
        }
        if (tempSum>answer) {
            answer = tempSum;
            x = i; y = 1;
        }
        for (int j=k+1; j<=n; j++) {
            tempSum = tempSum + verticalSumMatrix[i][j] - verticalSumMatrix[i][j-k];
            if (tempSum>answer) {
                answer = tempSum;
                x = i; y = j-k+1;
            }
        }
    }
    for(int i=x; i<=x+k-1; i++) {
        for(int j=y; j<=y+k-1; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}



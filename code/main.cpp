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


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int m, n;
    cin>>m>>n;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }
    
    int dpMatrix[m][n];
    
    for(int j=0; j<n; j++) {
        for (int i=0; i<m; i++) {
            if (i == 0 && j ==0) {
                dpMatrix[0][0] = matrix[0][0];
                continue;
            }
            int minVal = INT_MAX;
            int leftVal = (j-1>=0) ? dpMatrix[i][j-1] : INT_MAX;
            int topVal = (i-1>=0) ? dpMatrix[i-1][j] : INT_MAX;
            int topLeftVal = (i-1>=0 && j-1>=0) ? dpMatrix[i-1][j-1] : INT_MAX;
            minVal = minVal<leftVal ? minVal :leftVal;
            minVal = minVal<topVal ? minVal : topVal;
            minVal = minVal<topLeftVal ? minVal : topLeftVal;
            dpMatrix[i][j] = minVal + matrix[i][j];
        }
    }
    
    cout<<dpMatrix[m-1][n-1]<<endl;
    return 0;
}




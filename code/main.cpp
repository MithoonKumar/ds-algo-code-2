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

void rotateMatrix(int r, int c, int size) {
    int row = r, col = c;
    vector<int>nums;
    for(int i=r; i<=r; i++) {
        for(int j=c; j<=c+size-2; j++) {
            nums.push_back(matrix[i][j]);
        }
    }
    c = c+size-1;
    for(int i=r; i<=r+size-2; i++) {
        for(int j=c; j<=c; j++) {
            nums.push_back(matrix[i][j]);
        }
    }
    r = r+size-1;
    for(int i=r; i<=r; i++) {
        for(int j=c; j>=c-size+2; j--) {
            nums.push_back(matrix[i][j]);
        }
    }
    c = c-size+1;
    for(int i=r; i>=r-size+2; i--) {
        for(int j=c; j<=c; j++) {
            nums.push_back(matrix[i][j]);
        }
    }
    vector<int> rotatedVec;
    rotatedVec.push_back(nums[nums.size()-1]);
    for (int i=0; i<nums.size()-1; i++) {
        rotatedVec.push_back(nums[i]);
    }
    rotatedVec.push_back(nums[0]);
    int count = 0;
    for(int i=row; i<=row; i++) {
        for(int j=col; j<=col+size-2; j++) {
            matrix[i][j] = rotatedVec[count++];
        }
    }
    col = col + size -1;
    for(int i=row; i<=row+size-2; i++) {
        for(int j=col; j<=col; j++) {
            matrix[i][j] = rotatedVec[count++];
        }
    }
    row = row + size -1;
    for(int i=row; i<=row; i++) {
        for(int j=col; j>=col-size+2; j--) {
            matrix[i][j] = rotatedVec[count++];
        }
    }
    col = col - size + 1;
    for(int i=row; i>=row-size+2; i--) {
        for(int j=col; j<=col; j++) {
            matrix[i][j] = rotatedVec[count++];
        }
    }
    
    row = row - size + 1;
    size = size - 2;
    if (size >= 2) {
        rotateMatrix(row+1, col+1, size);
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>matrix[i][j];
        }
    }
    
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    rotateMatrix(1, 1, n);
    
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}



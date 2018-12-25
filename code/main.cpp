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

bool hasHamiltonianCycle(int node, int visited[], int len, int count) {
    if (count == len-1 && matrix[node][0]) {
        if (matrix[node][0]) {
            return true;
        } else {
            return false;
        }
    }
    visited[node] = 1;
    for (int i=0; i<len; i++) {
        if (matrix[node][i] && !visited[i]) {
            bool temp = hasHamiltonianCycle(i, visited, len, count+1);
            if (temp) {
                return true;
            }
        }
    }
    return false;
    
}


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }
    int visited[n];
    for (int i=0; i<n; i++) {
        visited[i] = 0;
    }
    cout<<hasHamiltonianCycle(0, visited, n, 0);
    return 0;
}



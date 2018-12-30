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
    int n, k;
    cin>>n>>k;
    int matrix[k+1][n+1];
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=k; i++) {
            cin>>matrix[i][j];
        }
    }
    map<int, int>hashMap;
    for(int i=1; i<=k; i++) {
        for (int j = 1; j<=n-1; j++) {
            if (matrix[i][j]) {
                hashMap[k] = 1;
            }
        }
    }
    vector<double>answer;
    int totalCount = 1;
    for (int i=1; i<=k; i++) {
        totalCount+= matrix[i][n];
    }
    for (int i=1; i<=k; i++) {
        if (hashMap[i]) {
            double ans = ((double)(1+matrix[i][n]))/((double)totalCount);
            answer.push_back(ans);
        } else {
            double ans = ((double)(matrix[i][n]))/((double)totalCount);
            answer.push_back(ans);
        }
    }
    for (int i=0; i<k; i++) {
        cout<<answer[i] <<endl;
    }
    return 0;
}


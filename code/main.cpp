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
    int r, c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin>>arr[i][j];
        }
    }
    
    for (int j=1; j<c; j++) {
        for(int i=0; i<r; i++) {
            int upVal, downVal, midVal;
            upVal = -1;
            downVal = -1;
            midVal = -1;
            if (i-1>=0) {
                upVal = arr[i-1][j-1];
            }
            if (i+1<=r-1) {
                downVal = arr[i+1][j-1];
            }
            midVal = arr[i][j-1];
            int maxVal = max(max(upVal, downVal), midVal);
            arr[i][j] = arr[i][j] + maxVal;
        }
    }
    int ans = -1;
    for (int i=0; i<r; i++) {
        ans = ans>arr[i][c-1] ? ans : arr[i][c-1];
    }
    cout<<ans<<endl;
    return 0;
}

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
    //freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    long long t;
    cin>>t;
    while(t--) {
        long long n,m;
        cin>>n>>m;
        long long arr[n][7];
        for (long long i = 0; i < n; i++) {
            for(long long j = 0; j < 7; j++) {
                arr[i][j] = 0;
            }
        }
        for (long long k = 0; k < m; k++) {
            long long c, r, z;
            cin>>r>>c>>z;
            arr[r-1][c-1] = max(arr[r-1][c-1], z);
        }
//        for (long long i = 0; i < n; i++) {
//            for(long long j = 0; j < 7; j++) {
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        
        
        for (long long i = 1; i < n; i++) {
            for (long long j = 0; j < 7 ; j++) {
                if (arr[i][j] != 0) {
                    long long maxVal = 0;
                    for (long long k = 0; k < 7; k++) {
                        if (k == j) {
                            continue;
                        }
                        maxVal = max(arr[i-1][k], maxVal);
                    }
                    if (maxVal == 0) {
                        arr[i][j] = 0;
                    } else {
                        arr[i][j] += maxVal;
                    }
                    
                }
            }
        }
        long long res = 0;
        for (long long j = 0; j < 7; j++) {
            res = max(arr[n-1][j], res);
        }
        if (res == 0) {
            cout<<-1<<endl;
        } else {
            cout<<res<<endl;
        }
    }
    
    return 0;
}

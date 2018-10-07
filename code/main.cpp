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

double findDistance (int x1, int y1, int x2, int y2) {
    double ans = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    return ans;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    
    int n,q;
    cin>>n>>q;
    int arr [n][3];
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < 3; j++) {
            arr[i][j] = 0;
        }
    }
    int answer [1000006] = {0};
    for (int i = 0; i < n ; i++) {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            //deciding the relative positions of the circles
            double dbcs = findDistance(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
            double sumOfRadii = arr[i][2] + arr[j][2];
            double maxValue = sumOfRadii + dbcs;
            double minValue = 0;
            double R = max(arr[i][2], arr[j][2]);
            double r = min(arr[i][2], arr[j][2]);
            if (sumOfRadii < dbcs) {
                minValue = dbcs - sumOfRadii;
            } else if (dbcs < R - r) {
                minValue = R - dbcs -r;
            } else {
                minValue = 0;
            }
            int maxValueI = floor(maxValue);
            int minValueI = floor(minValue);
            answer[minValueI]+=1;
            answer[maxValueI+1]-=1;
        }
    }
    for (int i = 1; i < 1000006; i++) {
        answer[i] = answer[i] + answer[i-1];
    }
    while(q--) {
        int k;
        cin>>k;
        cout<<answer[k] / 2<<endl;
    }
    return 0;
}

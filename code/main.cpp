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

int binarySearch(vector<int>balls, int s, int e, int index) {
    int mid = (s+e)/2;
    int midVal = balls[mid];
    if (midVal == index) {
        return mid;
    }
    if (index > midVal && balls[mid+1] >=index) {
        return mid+1;
    }
    if (index > midVal && balls[mid+1] <index) {
         return binarySearch(balls, mid+1, e, index);
    }
    if (index<midVal && mid == 0) {
        return mid;
    }
    if (index<midVal && balls[mid-1] < index) {
        return mid;
    } else {
        return binarySearch(balls, s, mid-1, index);
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    vector<int> balls;
    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        balls.push_back(val);
    }
    int ballIndex;
    cin>>ballIndex;
    vector<int> cum;
    cum.push_back(balls[0]);
    for (int i=1; i<balls.size(); i++) {
        cum.push_back(cum[i-1] + balls[i]);
    }
    cout<<binarySearch(cum, 0, balls.size()-1, ballIndex) + 1;
    return 0;
}




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

bool binarySearch(int arr[], int num, int s, int e) {
    if (s > e) {
        return false;
    }
    int mid = (s+e)/2;
    if (arr[mid] == num ){
        return true;
    } else if (num>arr[mid]) {
        return binarySearch(arr, num, mid+1, e);
    } else {
        return binarySearch(arr, num, s, mid-1);
    }
}

int main(){
    //freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int arr[] ={1, 2, 3, 4, 5, 6, 18, 19, 33, 34, 89, 101};
    while(true) {
        int temp;
        cin>>temp;
        cout<<binarySearch(arr, temp, 0, 11);
    }
    
    return 0;
}



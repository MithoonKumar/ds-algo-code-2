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
    int n;
    cin>>n;
    int arr[n+1];
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=n; i++) {
        arr[i] = (i-1) * arr[i-2] + arr[i-1];
    }
    cout<<arr[n]<<endl;
    return 0;
}

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
    long long t;
    cin>>t;
    long long arr [17][4] ;
    long long answer [1601][3];
    for (long long i = 0; i < 17; i++) {
        for (long long j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[1][1] = 1;
    answer[0][0] = 1;
    answer[0][1] = 0;
    answer[0][2] = 0;
    
    for (long long i = 1; i <= 1600; i++) {
        long long first = arr[2][1];
        arr[2][1] = arr[1][1];
        long long second = arr[8][2];
        for (long long j = 7; j >= 1; j--) {
            arr[j+1][2] = arr[j][2];
        }
        long long third = 2* arr[16][3];
        for (long long j = 15; j >= 1; j--) {
            arr[j+1][3] = arr[j][3];
        }
        arr[1][1] = third;
        arr[1][2] = first;
        arr[1][3] = second;
        long long bit = arr[1][1] + arr[2][1];
        long long nibble = 0 ;
        for (long long j = 1; j <= 8; j++) {
            nibble+=arr[j][2];
        }
        long long byte = 0 ;
        for (long long j = 1; j <= 16; j++) {
            byte+=arr[j][3];
        }
        answer[i][0] = bit;
        answer[i][1] = nibble;
        answer[i][2] = byte;
    }
    
    while(t--) {
        long long n;
        cin>>n;
        cout<<answer[n-1][0]<<" "<<answer[n-1][1]<<" "<<answer[n-1][2]<<endl;
    }
    
    return 0;
}

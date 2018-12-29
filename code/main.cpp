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

void printAllPrimeFactors(int num) {
    while((num%2) == 0) {
        cout<<2<<endl;
        num/=2;
    }
    
    for (int i=3;i<=sqrt(num); i++) {
        while ((num%i) == 0) {
            cout<<i<<endl;
            num/=i;
        }
    }
    if (num>1) {
        cout<<num<<endl;
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    printAllPrimeFactors(n);
    return 0;
}




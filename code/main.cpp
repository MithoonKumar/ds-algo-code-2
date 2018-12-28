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

bool check(int pos1, string firstString, int pos2, string secondString, int pos3, string finalString) {
    if(pos3 == finalString.length()) {
        return true;
    }
    bool first = false, second = false;
    if (pos1<firstString.length() && firstString[pos1] == finalString[pos3]) {
        first = check(pos1+1, firstString, pos2, secondString, pos3+1, finalString);
    }
    if (pos2<secondString.length() && secondString[pos2] == finalString[pos3]) {
        second = check(pos1, firstString, pos2+1, secondString, pos3+1, finalString);
    }
    return first || second;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    string firstString, secondString, finalString;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>firstString>>secondString>>finalString;
        check(0, firstString, 0, secondString, 0, finalString)? cout<<"yes"<<endl : cout<<"no"<<endl;
    }
    return 0;
}




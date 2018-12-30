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

void printAllPermutations(string str, string pStr, bool visited[], int tempLength, int length) {
    if(tempLength == length) {
        cout<<pStr<<endl;
        return;
    }
    for(int i=0; i<str.length(); i++) {
        if(!visited[i]) {
            pStr.push_back(str[i]);
            visited[i] = true;
            printAllPermutations(str, pStr, visited , tempLength+1, length);
            pStr.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    string str = "abc", permutedString="";
    bool visited[3] = {};
    printAllPermutations(str, permutedString, visited, 0, 3);
    return 0;
}


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

bool compareFunc(string str1, string str2) {
    string str3 = str1 + str2;
    string str4 = str2 + str1;
    if (str3 > str4) {
        return true;
    } else {
        return false;
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    vector<string> vec;
    for(int i=0; i<n; i++) {
        string temp;
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), compareFunc);
    string answer;
    for(int i=0; i<n; i++) {
        answer = answer + vec[i];
    }
    cout<<answer<<endl;
    
    return 0;
}



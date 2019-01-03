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
    return str1.length()<str2.length();
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    vector<string>vecString;
    for(int i=0; i<n; i++) {
        string str;
        cin>>str;
        vecString.push_back(str);
    }
    map<string, int>hashMap;
    for(int i=0; i<n; i++) {
        hashMap[vecString[i]] = 0;
    }
    sort(vecString.begin(), vecString.end(), compareFunc);
    
    for(int i=0; i<vecString.size(); i++) {
        string iStr = vecString[i];
        for(int j=0; j<iStr.length(); j++) {
            iStr.erase(j, 1);
            if (hashMap.find(iStr) != hashMap.end() && hashMap[iStr] + 1 > hashMap[vecString[i]]) {
                hashMap[vecString[i]] = hashMap[iStr] + 1;
            }
            iStr = vecString[i];
        }
    }
    
    int answer = INT_MIN;
    map<string, int>::iterator it;
    for ( it = hashMap.begin(); it != hashMap.end(); it++ )
    {
        answer = it->second > answer ? it->second : answer;
    }
    cout<<answer<<endl;
    return 0;
}



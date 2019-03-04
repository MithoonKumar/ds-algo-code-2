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

int arr[1000][1000];

void recurse(vector<string>tempVec, vector<vector<string>>&ans, int currPos, int len, string &s) {
    if (currPos == len) {
        cout<<"answering"<<endl;
        ans.push_back(tempVec);
        return;
    }
    for(int i=currPos; i<len; i++) {
        int tempLength = i - currPos + 1;
        if (arr[currPos][i]) {
            tempVec.push_back(s.substr(currPos, tempLength));
            recurse(tempVec, ans, i+1, len, s);
            tempVec.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int size = s.size();
    for (int i=0; i<s.size(); i++) {
        for (int j=0; j<s.size(); j++) {
            arr[i][j] = false;
        }
    }
    for (int i=0; i<s.size(); i++) {
        arr[i][i] = true;
    }
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] == s[i+1]) {
            arr[i][i+1] = true;
        } else {
            arr[i][i+1] = false;
        }
    }
    
    for (int j=2; j<size; j++) {
        for (int i=j-2; i>=0; i--) {
            if (s[i] == s[j] && arr[i+1][j-1]) {
                arr[i][j] = true;
            } else {
                arr[i][j] = false;
            }
        }
    }
    vector<vector<string>>ans;
    vector<string>tempVec;
    cout<<"Hello"<<endl;
    recurse(tempVec, ans, 0, s.size(), s);
    cout<<"answered"<<endl;
    return ans;
}


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    string str;
    cin>>str;
    partition(str);
    return 0;
}




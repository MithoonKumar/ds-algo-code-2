

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> convert (string s) {
    vector<string> vec;
    string temp = "";
    bool pushed = true;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ' && temp != "") {
            vec.push_back(temp);
            temp = "";
            pushed = true;
        } else {
            temp.push_back(s[i]);
            pushed = false;
        }
    }
    if (!pushed) {
        vec.push_back(temp);
    }
    return vec;
}

bool oneLine (vector<string> vec) {
    
    int size = 0;
    for (int i=0 ; i<vec.size(); i++) {
        size = size + vec[i].size() + 1;
    }
    if (size <= 30) {
        return true;
    }
    return false;
}

int giveCount(vector<string> vec) {
    int count = 0;
    int tempSize = 0;
    int counter = 0;
    while (counter<vec.size()) {
        tempSize = vec[counter].size() + 1;
        if (count > 9) {
            if (tempSize > 24) {
                count++;
            } else {
                counter++;
            }
        } else {
            if (tempSize > 23) {
                count++;
            } else {
                counter++;
            }
        }
    }
    return count;
}

int main() {
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    vector<string>vec;
    string str;
    while(true) {
        getline(cin, str);
        if (str == "") {
            break;
        } else {
            vec.push_back(str);
        }
    }
    
    for (int i=0; i<vec.size(); i++) {
        vector<string> strVec = convert(vec[i]);
        if (oneLine(strVec)) {
            cout<<1<<endl;
        } else {
            cout<<giveCount(strVec)<<endl;
        }
    }
    return 0;
}


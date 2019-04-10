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

void generateAllCombinations(int n, int k, int currPos, vector<int>arr, vector<vector<int>>&list) {
    
    if (arr.size() == k) {
        list.push_back(arr);
        return;
    }
    if (currPos > n) {
        return;
    }
    arr.push_back(currPos);
    generateAllCombinations(n, k, currPos+1, arr, list);
    arr.pop_back();
    generateAllCombinations(n, k, currPos+1, arr, list);
    
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>list;
    vector<int>arr;
    generateAllCombinations(n, k, 1, arr, list);
    return list;
}

int main() {
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    int n, k;
    //cin>>n>>k;
    n = 3;
    k = 2;
    vector<vector<int>> list = combine(n, k);
    for (int i=0; i<list.size(); i++) {
        for (int j=0; j<list[i].size(); j++) {
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

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


using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int findRight(vector<int>&a, int s, int e, int num) {
    int right = -1;
    for (int i=e; i>=s; i--) {
        if (a[i]>num) {
            right = i;
        }
    }
    return right;
}

int findLeft(vector<int>&a, int s, int e, int num) {
    int left = -1;
    for (int i=s; i<=e; i++) {
        if (a[i]<num) {
            left = i;
        }
    }
    return left;
}
bool checkTruth(vector<int>&a, int s, int e, int size) {
    if (s>size || e>size) {
        return true;
    }
    int right = findRight(a, s+1, e, a[s]);
    int left = findLeft(a, s+1, e, a[s]);
    if (right!=-1 && left !=-1 && right>left) {
        bool leftTrue = checkTruth(a, s+1, left, left);
        bool rightTrue = checkTruth(a, right, e, e);
        if (leftTrue && rightTrue) {
            return true;
        }
    } else if (right == -1) {
        bool leftTrue = checkTruth(a, s+1, left, left);
        if (leftTrue) {
            return true;
        }
    } else if (left == -1){
        bool rightTrue = checkTruth(a, right, e, e);
        if (rightTrue) {
            return true;
        }
    }
    return false;
}


string isValid(vector<int> a) {
    if (a.size() == 0) {
        return "YES";
    } else {
        int size = a.size();
        if (checkTruth(a, 0, size-1, size-1)) {
            return "YES";
        } else {
            return "NO";
        }
    }
    
}

int main() {
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    int n;
    cin>>n;
    vector<int>nums;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<isValid(nums)<<endl;;
    return 0;
}

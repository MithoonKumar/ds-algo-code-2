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

struct obj {
    int status;
    double value;
};

int anotherPartitionIndex(int p1, int size1, int size2) {
    return (size1 + size2 + 1)/2 - p1;
}

obj checkTruth(vector<int>nums1, vector<int>nums2, int p1, int p2) {
    int firstLeft = p1>0 ? nums1[p1-1] : INT_MIN;
    int firstRight = p1<nums1.size() ? nums1[p1] : INT_MAX;
    int secondLeft = p2>0 ? nums2[p2-1] : INT_MIN;
    int secondRight = p2<nums2.size() ? nums2[p2] : INT_MAX;
    int size1 = nums1.size();
    int size2 = nums2.size();
    obj statusObj;
    if (firstLeft <= secondRight && firstRight>=secondLeft) {
        statusObj.status = 0;
        if ((size1 + size2)%2 == 0) {
            statusObj.value = min(firstRight, secondRight) + max(firstLeft, secondLeft);
            statusObj.value = statusObj.value / 2;
        } else {
            statusObj.value =  max(firstLeft, secondLeft);
        }
    } else if (firstLeft>secondRight) {
        statusObj.status = -1;
    } else {
        statusObj.status = +1;
    }
    return statusObj;
}

double binarySearch(vector<int>nums1, vector<int>nums2, int s, int e) {
//    if (s>e) {
//        return 0;
//    }
    int mid = s + (e-s)/2;
    int p1 = mid;
    int p2 = anotherPartitionIndex(p1, nums1.size(), nums2.size());
    obj statusObj = checkTruth(nums1, nums2, p1, p2);
    if (statusObj.status == 0) {
        return statusObj.value;
    } else if (statusObj.status == -1) {
        return binarySearch(nums1, nums2, s, mid-1);
    } else {
        return binarySearch(nums1, nums2, mid+1, e);
    }
}
double median(vector<int>num) {
    int mid = (num.size() - 1)/2;
    if ((num.size()%2) == 0) {
        double val = num[mid] + num[mid+1];
        return val/2;
    } else {
        return num[mid];
    }
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0) {
        return median(nums2);
    }
    if (nums2.size() == 0) {
        return median(nums1);
    }
    
    return binarySearch(nums1, nums2, 0, nums1.size());
}

int main() {
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    int n, m;
    cin>>n>>m;
    vector<int>nums1, nums2;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        nums1.push_back(temp);
    }
    for (int i=0; i<m; i++) {
        int temp;
        cin>>temp;
        nums2.push_back(temp);
    }
    if (nums1.size() <= nums2.size()) {
        cout<<findMedianSortedArrays(nums1, nums2);
    } else {
        cout<<findMedianSortedArrays(nums2, nums1);
    }
    
    return 0;
}

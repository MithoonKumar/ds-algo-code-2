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

int findIndex(vector<int>vec, int s, int e) {
    if(s == e) {
        return s;
    }
    if (vec[s]<vec[e]) {
        return s;
    }
    int mid = (s+e)/2;
    if (mid-1>=0) {
        if (vec[mid]<vec[mid-1]) {
            return mid;
        }
    }
    if (vec[mid] > vec[s]) {
        return findIndex(vec, mid+1, e);
    } else {
        return findIndex(vec, s, mid-1);
    }
}

int binarySearch(vector<int> vec, int s, int e, int num) {
    if(s>e) {
        return -1;
    }
    int mid = (s+e)/2;
    if (vec[mid] == num) {
        return mid;
    }
    if (vec[mid]<num) {
        return binarySearch(vec, mid+1 , e, num);
    } else {
        return binarySearch(vec, s, mid-1, num);
    }
}



int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    vector<int>A;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        cout<<temp<<" ";
        A.push_back(temp);
    }
    int B;
    cin>>B;
    int partition = findIndex(A, 0 ,A.size()-1);
    int index1 = binarySearch(A, 0, partition-1, B);
    int index2 = binarySearch(A, partition, A.size()-1, B);
    if (index1 != -1) {
        cout<<index1<<endl;
    } else {
        cout<<index2<<endl;
    }
    return 0;
}




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
void heapifyMin(int index);
int heapArr[1000];
int heapSize = 0;

int parent(int i){
    return (i-1)/2;
}

int leftChild(int i) {
    return 2*i+1;
}

int rightChild(int i) {
    return 2*i+2;
}

void swap(int pos1, int pos2) {
    int temp = heapArr[pos1];
    heapArr[pos1] = heapArr[pos2];
    heapArr[pos2] = temp;
}

void insertInMinHeap(int num){
    heapArr[heapSize] = num;
    heapSize++;
    int pos = heapSize-1;
    while (pos!=0 && heapArr[parent(pos)] > heapArr[pos]) {
        swap(parent(pos), pos);
    }
}

void deleteMin() {
    if (heapSize == 0) {
        return;
    }
    int root = heapArr[heapSize-1];
    heapArr[0] = root;
    heapSize--;
    heapifyMin(0);
}

void heapifyMin(int index) {
    int val = heapArr[index];
    int leftChildVal = leftChild(index)<heapSize-1 ? heapArr[leftChild(index)] : INT_MAX;
    int rightChildVal = rightChild(index)<heapSize-1 ? heapArr[rightChild(index)] :INT_MAX;
    int min = (val < leftChildVal ? val : leftChildVal) < rightChildVal ? (val < leftChildVal ? val : leftChildVal) : rightChildVal;
    if (val == min) {
        return;
    } else if (min == leftChildVal) {
        swap(index, leftChild(index));
        heapifyMin(leftChild(index));
    } else {
        swap(index, rightChild(index));
        heapifyMin(rightChild(index));
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        insertInMinHeap(temp);
    }
    deleteMin();
    
    for(int i=0; i<heapSize; i++) {
        cout<<heapArr[i] <<" ";
    }
    
    return 0;
}



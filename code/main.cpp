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

struct node {
    int num;
    node * left, * right;
    node(int number){
        num = number;
        left = NULL;
        right = NULL;
    }
};

void modifyBst(node * root, int &sum) {
    if (root == NULL) {
        return;
    }
    if (root->right) {
        modifyBst(root->right, sum);
    }
    int tempSum = sum;
    sum  = sum + root->num;
    root->num = root->num + tempSum;
    if (root->left) {
        modifyBst(root->left, sum);
    }
}


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    node * root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);
    int sum = 0;
    modifyBst(root, sum);
    return 0;
}


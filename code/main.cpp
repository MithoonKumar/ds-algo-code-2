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
    int val;
    node * left;
    node * right;
    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int getSizeOfTree(node * root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + getSizeOfTree(root->left) + getSizeOfTree(root->right);
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;

    node *root        = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);
    root->left->left->right       = new node(3);
    root->left->left->left         = new node(4);
    cout<<getSizeOfTree(root);
    return 0;
    
}



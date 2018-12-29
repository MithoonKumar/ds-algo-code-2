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

bool isBST(node * root, int lowerBound, int upperBound) {
    if (root == NULL) {
        return false;
    }
    bool leftCondition = true, rightCondition = true;
    if (root->left) {
        if (root->left->num >lowerBound && root->left->num <root->num) {
            leftCondition = isBST(root->left, lowerBound, root->num);
        } else {
            leftCondition = false;
        }
    }
    if (root->right) {
        if (root->right->num >root->num && root->right->num <upperBound) {
            rightCondition = isBST(root->right, root->num, upperBound);
        } else {
            rightCondition = false;
        }
    }
    return leftCondition && rightCondition;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    node *root = new node(1);
    root->left = new node(1);
    
    if (isBST(root, INT_MIN, INT_MAX)) {
        cout << "Is BST"<<endl;
    }
    else {
        cout << "Not a BST"<<endl;
    }
    
    return 0;
}


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
    char val;
    node * left;
    node * right;
    node(char val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPos(vector<char>inorder, char c) {
    for (int i=0; i<inorder.size(); i++) {
        if(inorder[i] == c ) {
            return i;
        }
    }
    return -1;
}

node * constructBinaryTree(vector<char>inorder, vector<char>preorder, int &pos, node *root) {
    int rootPos = findPos(inorder, preorder[pos]);
    vector<char>leftInorder, rightInorder;
    for(int i=0; i<inorder.size(); i++) {
        if (i<rootPos) {
            leftInorder.push_back(inorder[i]);
        } else if (i>rootPos){
            rightInorder.push_back(inorder[i]);
        }
    }
    root = new node(preorder[pos]);
    pos++;
    if (leftInorder.size()>0) {
        root->left = constructBinaryTree(leftInorder, preorder, pos, root->left);
    }
    if (rightInorder.size()>0) {
       root->right = constructBinaryTree(rightInorder, preorder, pos, root->right);
    }
    return root;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    vector<char> inorder, preorder;
    inorder.push_back('d');
    inorder.push_back('b');
    inorder.push_back('e');
    inorder.push_back('a');
    inorder.push_back('f');
    inorder.push_back('c');
    
    preorder.push_back('a');
    preorder.push_back('b');
    preorder.push_back('d');
    preorder.push_back('e');
    preorder.push_back('c');
    preorder.push_back('f');
    node *root = NULL;
    int pos = 0;
    root = constructBinaryTree(inorder, preorder, pos, root);
    return 0;
}



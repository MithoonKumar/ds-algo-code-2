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

struct comb {
    node* first;
    int second;
    comb(node * f, int s) {
        this->first = f;
        this->second = s;
    }
};

void printLeftBoundary(node *root){
    if (root == NULL || (root->left == NULL && root->right == NULL) ) {
        return;
    } else if (root->left != NULL){
        cout<<root->val<<" ";
        printLeftBoundary(root->left);
    } else {
        cout<<root->val<<" ";
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(node *root){
    if (root == NULL || (root->left == NULL && root->right == NULL) ) {
        return;
    } else if (root->right != NULL){
        cout<<root->val<<" ";
        printLeftBoundary(root->right);
    } else {
        cout<<root->val<<" ";
        printLeftBoundary(root->left);
    }
}

void printAllLeafNodes(node *root){
    if (root == NULL) {
        return;
    } else if (root->left == NULL && root->right == NULL){
        cout<<root->val<<" ";
        return;
    }
    if (root->left != NULL){
        printAllLeafNodes(root->left);
    }
    if (root->right != NULL){
        printAllLeafNodes(root->right);
    }
}

node * getDivergencePoint(node * root) {
    if(root == NULL) {
        return NULL;
    } else if ((root->left != NULL && root->right != NULL) || (root->left == NULL && root->right == NULL) ){
        cout<<root->val<<" ";
        return root;
    } else if (root->left != NULL) {
        cout<<root->val<<" ";
        return getDivergencePoint(root->left);
    } else {
        cout<<root->val<<" ";
        return getDivergencePoint(root->right);
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;

    node *root        = new node(20);
    root->left        = new node(8);
    root->right       = new node(22);
    root->left->left  = new node(4);
    root->left->right = new node(12);
    root->left->right->left  = new node(10);
    root->left->right->right = new node(14);
    root->right->right = new node(25);
    node * divergencePoint = getDivergencePoint(root);
    cout<<endl;
    printLeftBoundary(divergencePoint->left);
    cout<<endl;
    printRightBoundary(divergencePoint->right);
    cout<<endl;
    printAllLeafNodes(root);
    return 0;
}



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

void printLeftView(node *root){
    map<int, int>hashMap;
    queue<comb> q;
    comb rootComb = comb(root, 0);
    q.push(rootComb);
    while(q.size()>0){
        if(!hashMap[q.front().second]) {
            hashMap[q.front().second] = 1;
            cout<<q.front().first->val<<" ";
        }
        if (q.front().first->left != NULL) {
            q.push(comb(q.front().first->left,  q.front().second + 1));
        }
        if (q.front().first->right != NULL) {
            q.push(comb(q.front().first->right,  q.front().second + 1));
        }
        q.pop();
    }
}


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;

    node *root        = new node(4);
    root->left        = new node(5);
    root->right       = new node(2);
    root->right->left  = new node(3);
    root->right->right = new node(1);
    root->right->left->left  = new node(6);
    root->right->left->right = new node(7);
    printLeftView(root);
    return 0;
}



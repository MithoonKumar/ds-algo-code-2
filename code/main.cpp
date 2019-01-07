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


/*Please note that it's Function problem i.e.
 you need to write your solution in the form of Function(s) only.
 Driver Code to call/invoke your function is mentioned above.*/

//Structure of the Node of the binary tree is as
 struct Node
 {
 int data;
 struct Node *left;
 struct Node *right;
 };
 
// function should return the root of the new binary tree formed
Node * createBinaryTree(Node *root, int pre[], char preLN[], int &pos) {
    Node *newNode = new Node();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = pre[pos];
    if(preLN[pos] == 'L') {
        pos++;
        return newNode;
    } else {
        pos++;
        newNode->left = createBinaryTree(newNode->left, pre, preLN, pos);
        newNode->right = createBinaryTree(newNode->right, pre, preLN, pos);
    }
    return newNode;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    Node *root = NULL;
    if (n == 0) {
        return root;
    }
    int pos = 0;
    root = createBinaryTree(root, pre, preLN, pos);
    return root;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    int pre[n];
    char preLN[n];
    
    for(int i=0; i<n; i++) {
        cin>>pre[i];
    }
    
    for(int i=0; i<n; i++) {
        cin>>preLN[i];
    }
    cout<<endl;
    Node * root;
    root = constructTree(n, pre, preLN);
    return 0;
}



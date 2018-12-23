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

struct trieNode {
    bool isEndOfWord;
    trieNode * chidlren[26];
    trieNode() {
        this->isEndOfWord = false;
        for (int i=0; i<26; i++) {
            this->chidlren[i] = NULL;
        }
    }
};




void insert(string str, int pos, trieNode * root) {
    if (root->chidlren[str[pos]-'a'] == NULL) {
        root->chidlren[str[pos]-'a'] = new trieNode();
    }
    if (pos+1 == str.length()) {
        root->chidlren[str[pos]-'a']->isEndOfWord = true;
    } else {
        insert(str, pos+1, root->chidlren[str[pos]-'a']);
    }
}

bool searchT(string str, int pos, trieNode * root) {
    if (!root->chidlren[str[pos]-'a']) {
        return false;
    } else {
        if (pos+1 == str.length()) {
            if (root->chidlren[str[pos]-'a']->isEndOfWord) {
                return true;
            } else {
                return false;
            }
        } else {
            return searchT(str, pos+1, root->chidlren[str[pos]-'a']);
        }
    }
}


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n;
    cin>>n;
    string strings[n];
    trieNode * root = new trieNode();
    for (int i=0; i<n; i++) {
        cin>>strings[i];
        insert(strings[i],0, root);
    }
    
    searchT("the",0, root)? cout<<"found"<<endl :cout<< "not found"<<endl;
    searchT("these",0, root)? cout<<"found"<<endl :cout<< "not found"<<endl;
    searchT("their", 0, root)?cout<< "found"<<endl :cout<< "not found"<<endl;
    searchT("thaw", 0, root)?cout<< "found"<<endl :cout<< "not found"<<endl;
    
    return 0;
}



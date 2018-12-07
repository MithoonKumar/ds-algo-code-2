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

int adj[100][100];

void dfs (int parent, int node, int *visited, int len, vector<int>store) {
    visited[node] = 1;
    store.push_back(node);
    for (int i = 1; i <= len; i++) {
        if(parent !=i && adj[node][i]) {
            if (visited[i] == 1) {
                int index =(int)store.size()-1;
                cout<<i<<" ";
                while(1) {
                    cout<<store[index--]<<" ";
                    if (store[index] == i) {
                        break;
                    }
                }
                cout<<endl;
            }
            if (visited[i]==0){
                dfs(node, i, visited, len, store);
            }
        }
    }
    visited[node] = 2;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n, edges;
    cin>>n>>edges;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n ;j++) {
            adj[i][j] = 0;
        }
    }
    for(int i = 0; i < edges; i++) {
        int a,b;
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int visited[n+1];
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    vector<int>store;
    dfs(0, 1, visited, n, store);
    return 0;
}

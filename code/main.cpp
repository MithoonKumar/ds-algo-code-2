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
vector<vector<int> > listOfCycles;

void dfs(int parent, int node, int visited[], vector<int>adj[], vector<int>stack) {
    stack.push_back(node);
    visited[node] = 1;
    for(int i=0; i<adj[node].size(); i++) {
        if (parent != adj[node][i]) {
            if (visited[adj[node][i]] == 0) {
                dfs(node, adj[node][i], visited, adj, stack);
            } else if(visited[adj[node][i]] == 1){
                listOfCycles.push_back(stack);
            }
        }
    }
    visited[node] = 2;
    stack.pop_back();
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n, e;
    cin>>n>>e;
    vector<int>adj[n+1];
    for (int i=0; i<e; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int visited[n+1];
    for (int i=0; i<=n; i++) {
        visited[i] = 0;
    }
    vector<int>stack;
    dfs(0, 1, visited, adj, stack);
    for(int i=0; i<listOfCycles.size(); i++) {
        for(int j=0; j<listOfCycles[i].size(); j++){
            cout<<listOfCycles[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



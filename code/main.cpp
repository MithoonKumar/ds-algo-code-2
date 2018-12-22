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

void breadthFirstSearch(int node, int n, vector<int> adj[]) {
    int visited[n];
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }
    queue<int>q;
    q.push(node);
    visited[node] = 1;
    while(q.size()>0) {
        int topNode = q.front();
        cout<<topNode<<" ";
        q.pop();
        for(int i=0; i<adj[topNode].size(); i++) {
            if (visited[adj[topNode][i]] == 0) {
                q.push(adj[topNode][i]);
                visited[adj[topNode][i]] = 1;
            }
        }
    }
    
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int n, e;
    cin>>n>>e;
    vector<int> adj[n];
    for (int i=0; i<e; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
    
    breadthFirstSearch(0, n, adj);
    return 0;
}



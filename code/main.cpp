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


struct comb {
    int r, c;
};

#include<queue>
void bfs(int i, int j, vector<vector<bool>>&visited, vector<vector<char>>&grid) {
    int totalRows = grid.size();
    int totalCols = grid[0].size();
    queue<comb>q;
    comb c;
    c.r = i;
    c.c = j;
    q.push(c);
    visited[i][j] = true;
    while(q.size()>0) {
        //cout<<"Hello"<<endl;
        comb topEle = q.front();
        q.pop();
        //left
        if (topEle.c-1>=0 && !visited[topEle.r][topEle.c-1] &&grid[topEle.r][topEle.c-1] == '1' ) {
            comb c;
            c.r = topEle.r;
            c.c = topEle.c-1;
            q.push(c);
            visited[topEle.r][topEle.c-1] = true;
        }
        //right
        if (topEle.c+1<totalCols && !visited[topEle.r][topEle.c+1] &&grid[topEle.r][topEle.c+1] == '1' ) {
            comb c;
            c.r = topEle.r;
            c.c = topEle.c+1;
            q.push(c);
            visited[topEle.r][topEle.c+1] = true;
        }
        //top
        if (topEle.r-1>=0 && !visited[topEle.r-1][topEle.c] &&grid[topEle.r-1][topEle.c] == '1' ) {
            comb c;
            c.r = topEle.r-1;
            c.c = topEle.c;
            q.push(c);
            visited[topEle.r-1][topEle.c] = true;
        }
        //bottom
        if (topEle.r+1<totalRows && !visited[topEle.r+1][topEle.c] &&grid[topEle.r+1][topEle.c+1] == '1' ) {
            comb c;
            c.r = topEle.r+1;
            c.c = topEle.c;
            q.push(c);
            visited[topEle.r+1][topEle.c] = true;
        }
        
    }
}



int numIslands(vector<vector<char>>& grid) {
    vector<vector<bool>>visited;
    int totalRows = grid.size();
    int totalCols = grid[0].size();
    for (int i=0; i<totalRows; i++) {
        vector<bool>tempVec;
        for (int j=0; j<totalCols; j++) {
            tempVec.push_back(false);
        }
        visited.push_back(tempVec);
    }
    int count = 0;
    for (int i=0; i<totalRows; i++) {
        for (int j=0; j<totalCols; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                count++;
                bfs(i, j, visited, grid);
            }
        }
    }
    return count;
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    vector<vector<char>>grid;
    int r, c;
    cin>>r>>c;
    for (int i=0; i<r; i++) {
        vector<char>tempVec;
        for (int j=0; j<c; j++) {
            char ch;
            cin>>ch;
            tempVec.push_back(ch);
        }
        grid.push_back(tempVec);
    }
    cout<<numIslands(grid);
    return 0;
}




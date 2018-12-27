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

bool matrix[100][100];

struct point {
    int r,c,distance;
    point(int a, int b, int d) {
        this->r = a;
        this->c = b;
        this->distance = d;
    }
};


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int m, n;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }
    
    int sr, sc, dr, dc;
    cin>>sr>>sc>>dr>>dc;
    if (sr == dr && sc == dc) {
        cout<<0;
        return 0;
    }
    queue<point> q;
    point starting =  point(sr, sc, 0);
    q.push(starting);
    int finalDistance = -1;
    bool visited[m][n];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }
    while(q.size()) {
        point p = q.front();
        q.pop();
        point p1 = point(p.r-1, p.c, p.distance+1);
        point p2 = point(p.r+1, p.c, p.distance+1);
        point p3 = point(p.r, p.c-1, p.distance+1);
        point p4 = point(p.r, p.c+1, p.distance+1);
        vector<point>points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        for (int z=0; z<points.size(); z++) {
            point tempPoint = points[z];
            int i = tempPoint.r;
            int j = tempPoint.c;
            if ((i>=0 && j>=0 && i<n && j<n) && !visited[i][j] && matrix[i][j]) {
                visited[i][j] = true;
                point tempPoint = point(i, j, p.distance+1);
                if (tempPoint.r == dr && tempPoint.c == dc) {
                    finalDistance = p.distance+1;
                } else {
                    q.push(tempPoint);
                }
            }
        }
        
 
        if (finalDistance != -1) {
            break;
        }
    }
    if (finalDistance == -1) {
        cout<<"Not reachable"<<endl;
    } else {
        cout<<finalDistance<<endl;
    }
    return 0;
}




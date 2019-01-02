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

struct point {
    int ele, dis;
    point(int ele, int dis) {
        this->ele = ele;
        this->dis = dis;
    }
};

int getMinDiceThrows(int moves[], int N) {
    bool visited[N];
    for(int i=0; i<N; i++) {
        visited[i] = false;
    }
    queue<point>q;
    int startingCoordinate = (moves[0] == -1 ? 0 : moves[0]);
    point starting = point(startingCoordinate, 0);
    q.push(starting);
    visited[0] = true;
    int answer = -1;
    while(!q.empty()) {
        point topElement = q.front();
        q.pop();
        for (int i= topElement.ele+1; i<=topElement.ele+6; i++) {
            if (i>=N) {
                continue;
            }
            int nextPoint = (moves[i] == -1 ? i : moves[i]);
            if (!visited[nextPoint]) {
                point tempPoint = point(nextPoint, topElement.dis+1);
                q.push(tempPoint);
                visited[nextPoint] = true;
                if (tempPoint.ele == N-1) {
                    answer = tempPoint.dis;
                    break;
                }
            }
        }
    }
    return answer;
}


int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;
    
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
    
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    
    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    return 0;
}



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

int findMinDistIndex(int visited[], int distances[], int len ) {
    int min = INT_MAX;
    int index = -1;
    for (int i=0; i<len; i++) {
        if (!visited[i] && distances[i]<min) {
            min = distances[i];
            index = i;
        }
    }
    return index;
}


void dijkastra(int matrix[9][9], int source) {
    int distances[9];
    int visited[9] = {};
    for (int i=0; i<9; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;
    int loop = 9-1;
    while(loop) {
        int index = findMinDistIndex(visited, distances, 9);
        visited[index] = 1;
        for (int i=0; i<9; i++) {
            if (matrix[index][i] && distances[i]>distances[index] + matrix[index][i]) {
                distances[i] = distances[index] + matrix[index][i];
            }
        }
        loop--;
    }
    for(int i=0; i<9; i++) {
        cout<<"Minimum distance of vertex " << i <<" from " <<source<< " is " << distances[i]<<endl;
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int adjMatrix[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    dijkastra(adjMatrix, 0);
    return 0;
}



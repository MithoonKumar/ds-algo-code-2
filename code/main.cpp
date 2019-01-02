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
int matrix[100][100];

pair<int, int> getCoordinates(int index, int m) {
    int r = index/m;
    int c = (index%m);
    pair<int, int>p;
    p.first = r;
    p.second = c;
    return p;
}

bool binarySearch(int num, int s, int e, int m) {
    if(s>e) {
        return false;
    }
    int mid =(s+e)/2;
    pair<int, int> midP = getCoordinates(mid, m);
    int midNum = matrix[midP.first][midP.second];
    if (midNum == num) {
        return true;
    } else if (midNum>num) {
        return binarySearch(num, s, mid-1, m);
    } else {
        return binarySearch(num, mid+1, e, m);
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int m;
    cin>>m;
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            cin>>matrix[i][j];
        }
    }
    for(int i=0; i<3; i++) {
        int num;
        cin>>num;
        if (num == -1) {
            break;
        }
        cout<<binarySearch(num, 0, m*m-1, m)<<endl;
    }
    
    
    return 0;
}



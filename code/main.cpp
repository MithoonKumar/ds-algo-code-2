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
    double x, y;
    point(double x, double y){
        this->x = x ;
        this->y = y;
    }
    point() {}
};

double findDistance(point first, point second) {
    return sqrt((first.x - second.x)*(first.x - second.x) + (first.y - second.y)*(first.y - second.y));
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    point p1 = point();
    point p2 = point();
    point p3 = point();
    point p4 = point();
    //pick first point and then start processing
    double d2, d3, d4;
    d2 = findDistance(p1, p2);
    d3 = findDistance(p1, p3);
    d4 = findDistance(p1, p4);
    bool answer = false;
    if (d2 == d3  && d2*d2 == 2*d4*d4) {
        if(findDistance(p4, p2) == findDistance(p4, p3) && findDistance(p4, p2) == d2) {
            answer = true;
        } else {
            answer = false;
        }
    } else if (d2 == d4  && d2*d2 == 2*d3*d3){
        if(findDistance(p3, p2) == findDistance(p3, p4) && findDistance(p3, p4) == d2) {
            answer = true;
        } else {
            answer = false;
        }
    } else if (d4 == d3  && d3*d3 == 2*d2*d2) {
        if(findDistance(p4, p2) == findDistance(p3, p2) && findDistance(p4, p2) == d4) {
            answer = true;
        } else {
            answer = false;
        }
    }
    cout<<answer<<endl;
    return 0;
}


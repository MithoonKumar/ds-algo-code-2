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

int findCategory(char c) {
    if (c>='0' && c<='9') {
        return 1;
    } else if (c>='A' && c<='Z') {
        return 2;
    } else if (c>='a' && c<='z') {
        return 3;
    } else {
        return 0;
    }
}

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    
    string str;
    int count  = 0;
    while (getline(cin, str)){
        count++;
        if (count==1) {
            continue;
        }
        int leftPointer = 0, rightPointer = (int)str.length()-1;
        bool answer = true;
        while(rightPointer>=leftPointer) {
            int leftCategory = findCategory(str[leftPointer]);
            int rightCategory = findCategory(str[rightPointer]);
            if(leftCategory && rightCategory) {
                if(leftCategory == rightCategory && str[rightPointer] == str[leftPointer]) {
                    rightPointer--;
                    leftPointer++;
                    continue;
                }
                if(leftCategory == 2 && rightCategory ==3 && str[leftPointer] + 'a' - 'A' == str[rightPointer]) {
                    rightPointer--;
                    leftPointer++;
                    continue;
                }
                if(leftCategory == 3 && rightCategory ==2 && str[leftPointer] - 'a' + 'A' == str[rightPointer]) {
                    rightPointer--;
                    leftPointer++;
                    continue;
                }
                answer = false;
                break;
            } else if(leftCategory == 0 && rightCategory == 0) {
                leftPointer++;
                rightPointer--;
            } else if (rightCategory == 0) {
                rightPointer--;
            } else {
                leftPointer++;
            }
        }
        answer? cout<<"YES"<<endl: cout<<"NO"<<endl;
    }
    return 0;
}



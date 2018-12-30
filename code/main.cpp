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

int main(){
    freopen("/Users/mithoon.k/Documents/github-repo/ds-algo-code/code/code/input.txt","r",stdin);
    faster;
    long long t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        long long monthDays [n];
        long long cumMonthDays [n];
        long long sumOfDays = 0;
        for (long long i=0; i<n; i++) {
            cin>>monthDays[i];
            if (i == 0) {
                cumMonthDays[0] = monthDays[i];
            } else {
                cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i];
            }
            sumOfDays += monthDays[i];
        }
        long long yb, mb, db, yc, mc, dc;
        cin>>yb>>mb>>db>>yc>>mc>>dc;
        long long numberOfLeapYears = 0, numberOfNonLeapYears = 0;
        if (yc-yb>1) {
            long long lowerBound = yb + 1;
            long long upperBound = yc -1;
            numberOfLeapYears = upperBound/4 - lowerBound/4 + ((lowerBound%4) == 0 ? 1 : 0);
            numberOfNonLeapYears = yc-yb-1 - numberOfLeapYears;
        }
        long long age = 0;
        age = age + sumOfDays*numberOfNonLeapYears;
        age = age + (sumOfDays+1)*numberOfLeapYears;
        if (yc-yb >=1) {
            long long numberOfDaysInBirthYear = (((yb%4) == 0) ? sumOfDays+1: sumOfDays) - (mb-2>=0 ? cumMonthDays[mb-2]: 0) - db + 1;
            long long numberOfDaysInCurrentYear = (mc-2>=0 ? cumMonthDays[mc-2]: 0) + dc;
            age = age + numberOfDaysInBirthYear + numberOfDaysInCurrentYear;
        } else {
            age = age + (mc-2>=0 ? cumMonthDays[mc-2]: 0) + dc - (mb-2>=0 ? cumMonthDays[mb-2]: 0) - db + 1;
        }
        cout<<age<<endl;
    }
    return 0;
}


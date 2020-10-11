#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <climits>


// Defines for some data types. 
#define li long int
#define ll long long int
#define ar array

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

#define MOD 1000000000+7
using namespace std;

int main() {

    int n;
    cin >> n;
    
    int dp[n+1] = {0};
        
    // The idea is to find the minimum number of steps
    // for numbers from 1, 2, 3, 4...n.
    // Lets say n = 123. Lets Solve(x) be the number of steps to reach 0. 
    // Now there are 3 possiblities, 
    // a1 => Solve(123 - 1) + 1.
    // b1 => Solve(123 - 2) + 1. 
    // c1 => Solve(123 - 3) + 1. 
    // So the answer would basically be min(a1, b1, c1).
    // So doing this from the front, i.e from 1,2,3 and so on, we will already have the 
    // answer till we reach n. 
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        dp[i] = INT_MAX-1;
        while(temp) {
            dp[i] = min(dp[i], dp[i-(temp%10)]+1);
            temp /= 10;
        }
    }       
    cout << dp[n];
    return 0;
}



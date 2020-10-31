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
    
    int n, x;
    cin >> n >> x;

    int coins[n];
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    int dp[x+1] = {0};
    dp[0] = 1;
    
    // The idea here is to find the number of ways to make a sum
    // with coins one by one. 
    // Basically reverse of what we did in the previous Coin-Combination problem 
    // where the order didn't matter. 
    // Doing this doesn't repeat the order.
    // For example: 
    // Coins: 2, 3, 5.
    // find all the sums possible with 2. 
    // Then with 3, if a sum which required 2, will be counted from what in the first round. 
    // And so one.
    for (int coin: coins) {
        for (int i = coin; i <= x; ++i) {
            dp[i] += dp[i-coin];
            dp[i]%=MOD;
        }
    }
    cout << dp[x];
    return 0;
}



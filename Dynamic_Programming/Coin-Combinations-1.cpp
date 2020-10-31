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

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int dp[x+1]={0};
    dp[0] = 1;
    
    // This is exact same as Dice Combinations.
    for (int i = 1; i <= x; ++i) {
        for (int coin: coins) {
            if (i-coin >= 0)
                dp[i] += dp[i-coin];
                dp[i] %= MOD;
        }
    }        
    
    cout << dp[x];
    return 0;
}



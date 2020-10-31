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
#define MAX(a,b) (a) > (b) ? a : b
#define MIN(a,b) (a) < (b) ? a : b

#define MOD 10000000+7
using namespace std;

int main() {
    
    int n, x;
    cin >> n >> x;
    
    int coins[n];
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    
    // Let Solve(x) be the number of coins needed to make x.
    // with the base case of Solve(0) = 0. The recurance relation would be,
    // MIN(Solve(x-C1)+1, Solve(x-C2)+1, Solve(x-C3)+1,...).
    // So using the same idea and memoizing it and doing it iterativily. 
    int dp[x+1] = {0};
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        dp[i] = INT_MAX;
        for (int coin : coins)
            if (i-coin >= 0)
                dp[i] = MIN(dp[i], dp[i-coin]+1);
    }
    if (dp[x] != INT_MAX)
        cout << dp[x];
    else 
        cout << "-1";
    return 0;
}



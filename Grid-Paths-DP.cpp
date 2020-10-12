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

using namespace std;

const int N=1000;
const int MOD = 1e9+7;

ll dp[N][N];

int main() {
    
    int n;
    cin >> n;
    char grid[n][n];

    for (int i = 0; i < n; ++i)
        for (int j= 0; j < n; ++j)
            cin >> grid[i][j];
    
    // The idea here like all DP problem is to first figure out the number of 
    // paths for 1x1 grid and then go up from there. This could either be '0' or '1', 
    // based on if a trap exists there or not. 
    // Now lets take an example of 2x2 grid.
    // Eg:-
    //   0 1 
    // 0 * *
    // 1 * *
    //
    // So here there are no traps, for simiplicity sake.
    // No. of path to 00 = 1.
    // No. of path to 01 = 1.
    // No. of path to 10 = 1.
    // No. of path to 11 = 2.
    //
    // The dp array will look like.
    //   0 1
    // 0 1 1
    // 1 1 2
    // 
    // So you can see the number of path to 'ij' is just dp[i-1][j] + dp[i][j-1].
    // Just take care of the bounds and you're good to go. 
    // Places where traps are there just put 0 there.
    //
    
    if (grid[0][0] == '.')
        dp[0][0] = 1;
    else
        dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                if (i-1 >= 0)
                    dp[i][j] = (dp[i][j]+dp[i-1][j]) % MOD;
                if (j-1 >= 0)
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
            else 
                dp[i][j] = 0;
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}



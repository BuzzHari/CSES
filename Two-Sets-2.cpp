#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <climits>

using namespace std;

// Defines for some data types. 
#define ll long long int
#define uint unsigned int
#define ar array

// Macors for some utility function. 
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(a,b) (a) < (b) ? (a) : (b)

const uint MOD =  1000000000+7;

int main() {
    
    
    int n;
    cin >> n;
    int total_sum = (n*(n+1))/2;
    if (total_sum%2) {
        cout << 0 << endl;
        return 0;
    }

    int half_sum = total_sum/2;
    
    //
    // Let Solve(n,x) be such the count of subsets of in range 1...n, which sum up to 'x'.
    //
    // So recurance relation will be: 
    //  If we choose to include 'n' in the set. 
    //      cnt = Solve(n-1, x-n);
    //  If we choose not inclue 'n' in the set.
    //      cnt = Solve(n-1, x);
    //  And, we'll need to sum of both, to get the total count.
    //  => Solve(n,x) = Solve(n-1, x-n) + Solve(n-1,x)
   

    // Let ways[i][j] be such the count of subsets of in range 1...i, which sum up to 'j'.
    vector<vector<int>> ways(n+1, vector<int>(half_sum+1, 0));
        
    // Base case. 
    ways[0][0] = 1; 
    
    // We are going till n-1, this way we always put the 'n' in the second subset,
    // and in doing so we don't count the same subset pair twice. 
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= half_sum; ++j) {
            
            ways[i][j] = ways[i-1][j];
            if (j-i >= 0)
                ways[i][j] = (ways[i][j] + ways[i-1][j-i]) % MOD ;
        }
    }
    
    cout << ways[n-1][half_sum];
    return 0;
}



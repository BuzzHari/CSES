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

    ll ways[n+1] = {0};
    ways[0] = 1;
    
    // Let Solve(x), be the number of ways x could be formed. 
    // So the recursion will just be Solve(x-1) + Solve(x-2)+..+Solve(x-6), 
    // with base case Solve(0) = 1.
    // The recursion can implemented with Memoization and iterativly as below. 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i-j >=0 ) {
                ways[i] += ways[i-j];
                ways[i] %=  MOD;
            }
        }                
    }
    cout << ways[n];
    return 0;
}



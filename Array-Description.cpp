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

const int N = 1e5+1;
const int M = 101;
int ways[N][M];

int main() {
    
    int n, m;
    cin >> n >> m;
    
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Let ways[i][j] be the number of ways array of lenght i+1, ends with value 'j'.
    // 
    // An array of lenght 'i', ending with 'j' is valid only if the value at 'i-1'th index,
    // is j-1, j or j+1. 
    // Hence dp relation is ways[i][j] = ways[i-1][j-1] + ways[i-1][j] + ways[i-1][j+1].
    //
    // For ex: 2 0 0, and the m=5.
    // ways-> i = 0, arr[i] = 2
    //      1 2 3 4 5 
    //    0 0 1 0 0 0 
    //    1 - - - - -      
    //    2 - - - - -, So i=0 postion is fixed so ways[0][2]=1.        
    // 
    // ways-> i = 1, arr[i] = 0
    //      1 2 3 4 5 
    //    0 0 1 0 0 0 
    //    1 1 1 1 0 0      
    //    2 - - - - -, So i=1 postion is not fixed so ways[0][j] is based on the 
    //    relation mentioned above. 
    //
    // ways-> i = 2, arr[i] = 0
    //      1 2 3 4 5 
    //    0 0 1 0 0 0 
    //    1 1 1 1 0 0      
    //    2 2 3 2 1 0, So i=2 postion is not fixed so just like the previous case.
    //
    //    In the end the answer would be total of all the ways for array lenght i = 3. 
    //    Which is 2+3+2+1 = 8.
    //
    //    NOTE: I have defined the array ways[][] in global, so all values are automatically 
    //    initialized to '0' as its stored in the .bss segment. So I didn't have to update array 
    //    with zeros when the condition weren't satisfied. 
    
    if (arr[0])
        ways[0][arr[0]] = 1;
    else 
        for (int i = 1; i <=m; ++i)
            ways[0][i] = 1;

    for (int i = 1; i < n; ++i) {
    
        if (arr[i]) {

            ways[i][arr[i]] = ((ways[i-1][arr[i]-1] + ways[i-1][arr[i]])%MOD + ways[i-1][arr[i]+1])%MOD;
        }
        else {
            for (int j = 1; j <= m; ++j) {
                ways[i][j] = ((ways[i-1][j-1] + ways[i-1][j])%MOD + ways[i-1][j+1])%MOD;        
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <=m; ++i) {
        ans = (ans+ways[n-1][i]) % MOD;
    }

    cout << ans;

    return 0;
}



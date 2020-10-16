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
    
    int x, y;
    cin >> x >> y;
    
    // If square already, print 0 and exit.
    if (x == y) {
        cout << 0;
        return 0;
    }
    
    // Let ways[i][j] be the number of cuts required for 
    // rectangle of dimensions i * j.
    // If i == j, ways[i][j] = 0.
    // Else for each horizontal cut keep track of the min ways and,
    // for each vertical cut keep track of min ways.
    //
    // ways[x][y] will the answer. 
    int ways[x+1][y+1];

    for (int i = 0; i <=x; ++i)
        ways[i][0] = 0;
    for (int i = 0; i <=y; ++i)
        ways[0][i] = 0;
    
    for (int i = 1; i <=x; ++i) {
        for (int j = 1; j <= y; ++j) {

            if (i==j)
                ways[i][j] = 0;
            else {
                ways[i][j] = 1e9;
                // Horizontal cuts.
                for (int k = 1; k < i; ++k) {
                    ways[i][j] = min(ways[i][j], ways[k][j]+ways[i-k][j]+1);
                }
                // Vertical cuts.
                for (int l = 1; l < j; ++l) {
                    ways[i][j] = min(ways[i][j], ways[i][l]+ways[i][j-l]+1);
                }
            }
        }
    }

    cout << ways[x][y]; 
    return 0;
}



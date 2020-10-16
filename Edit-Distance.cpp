#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <string>
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
const int N = 5001;
int dist[N][N];

int main() {
    
    string x, y;
    cin >> x;
    cin >> y;
    
    // Let dist[i][j] be the minimum number of moves to change x[:i] to y[:j].
    // where, x[:i] means the first characters of x[:i].
    
    dist[0][0] = 0;
    for (int i = 0; i <= x.size(); ++i) {
        for (int j = 0; j <= y.size(); ++j) {
            if (i || j)
                dist[i][j] = INT_MAX;
            if (i)
                // This is basically deleteing a character from x.
                // but we still have to modify the remaining character.
                // hence, 1+dist[i-1][j].
                dist[i][j] = min(dist[i][j], dist[i-1][j]+1);
            if (j)
                // This is basically inserting a character to end of x.
            dist[i][j] = min(dist[i][j], dist[i][j-1]+1);
                
                // This case is when we are transitioning from one character to another.
                // The charcaters can be equal so it'll just by dist[i-1][j-1].
                // if different add 1 as cost. 
            
            if ((i && j) && x[i-1] == y[j-1])
                dist[i][j] = min(dist[i][j], dist[i-1][j-1]);
            else if ((i&&j) && x[i-1] != y[j-1]) 
                dist[i][j] = min(dist[i][j], dist[i-1][j-1]+1);
            
            // Those are the 4 cases we have, the min of all four will be the minimum distance
            // required for d[i][j].
        }
    }

    /*
     *for (int i = 0; i < x.size(); ++i, cout<<"\n")
     *    for (int j =0; j < y.size(); ++j)
     *        cout << dist[i][j] << " " ;
     */

    cout << dist[x.size()][y.size()];

    return 0;
}



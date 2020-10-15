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
    
    /*
     *int (*dist)[5001];
     *dist = (int (*)[5001]) malloc(sizeof((*dist)[5001])*5001); 
     */
    //memset(dist,0, (x.size()*y.size())*sizeof(int));
    

    if (x[0] == y[0])
        dist[0][0] = 0;
    else 
        dist[0][0] = 1;
    for (int i = 1; i < y.size(); ++i){
        dist[0][i] += dist[0][i-1]+1;
    }
    for (int j = 1; j < x.size(); ++j)
        dist[j][0] += dist[j-1][0]+1;

    for (int i = 1; i < x.size(); ++i) {
        for (int j = 1; j < y.size(); ++j) {
                dist[i][j] = INT_MAX;
                dist[i][j] = min(dist[i][j], dist[i-1][j]+1);
                dist[i][j] = min(dist[i][j], dist[i][j-1]+1);
            if ((i&&j) && x[i] == y[j])
                dist[i][j] = min(dist[i][j], dist[i-1][j-1]);
            else if ((i&&j) && x[i] != y[j])
                dist[i][j] = min(dist[i][j], dist[i-1][j-1]+1);
        }
    }

    /*
     *for (int i = 0; i < x.size(); ++i, cout<<"\n")
     *    for (int j =0; j < y.size(); ++j)
     *        cout << dist[i][j] << " " ;
     */

    cout << dist[x.size()-1][y.size()-1];

    return 0;
}



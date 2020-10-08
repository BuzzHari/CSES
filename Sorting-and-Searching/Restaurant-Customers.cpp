#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <set>
#include <array>
// Defines for some data types. 
#define li long int
#define lli long long int
#define ar array

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

int main() {
    
    int n;
    cin >> n;
    // Inserting the entry and exit times in a set.
    // As {entry,1} and {exit,1}. Could also be a map.
    // The idea is that inserting into set/map sorts them by time. 
    // Now we just simulate entry and exit and keep track of max.
    set<ar<int,2>> times;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        times.insert({a,1});
        times.insert({b,-1});
    }        
    
    int c = 0, maxx = -1;
    for (ar<int,2> a: times) {
        c += a[1];
        maxx = max(c, maxx); 
    }
    cout << maxx;
    return 0;
}

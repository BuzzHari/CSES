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
#define lli long long int
#define ar array

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

int main() {
    
    int x, n;
    cin >> x >> n;
    
    // Lenths -> its count;
    map<int, int> length;
    
    // To keep track of the splits in the path due the placement of trafic light.
    set<int> splits;
    splits.insert(0);
    splits.insert(x);
    length[x] = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        auto it = splits.upper_bound(a);

        // The position on the right of the traffic light.
        int right = *it;
        --it;
        // The position on the left of the traffic light.
        int left  = *it;
        
        // Decreasing the count of the length because one of it is going
        // to get split into two.
        --length[right-left];
        
        if (length[right-left] == 0)
            length.erase(right-left);
        
        // Adding the new lengths to the map.
        ++length[right-a];
        ++length[a-left];
        // Inserting the new split.
        splits.insert(a);
    
        // Printing the largest length.
        cout << length.rbegin()->first << " ";

    }
    
    return 0;
}

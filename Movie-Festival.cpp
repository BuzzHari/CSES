#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <array>
#include <map>
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
    
    int n;
    cin >> n;

    // The idea is to sort the times basesd on the end time. 
    // Then compare the start time of the current moive with end time of the
    // last moive, if it's greater than equal to it then it's counted. 
    // Instead of map a simple 2d array, will also suffice, we just have to sort it. 
    map<int , int> moive;
    
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        moive[end] = start;
    }
    
    int ans = 0 , last = 0;
    for (auto it = moive.begin(); it!=moive.end(); ++it) {
        if (it->second >= last) {
            ++ans;
            last = it->first;
        }
    }

    cout << ans;
    return 0;
}

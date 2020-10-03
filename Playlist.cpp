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
    int arr[n];
    map<int, int> mymap;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }        
    
    int maxx_count = 0;
    // The idea is to keep a window a unique characters, 
    // So initally i, j points to intial element.
    // Increase j until I reach a duplicate. 
    // When I reach a duplicate, reduce the window from left till the 
    // window is valid again. That's basically ++i, and reducing the frequency
    // of ith element. 
    // Keep track of the largest window size achieved.
    for (int i = 0, j=0; i < n; ++i) {
        while (j < n && mymap[arr[j]] < 1) {
            mymap[arr[j]]+=1;
            // Increasing the window from right.
            ++j;
        } 
        // j-i is the size of the window. 
        maxx_count = max(j-i, maxx_count);
        // reducing the window from left.
        mymap[arr[i]]-=1;
        
        if (n-i+1 < maxx_count)
            break;
    }
    cout << maxx_count;
    return 0;
}

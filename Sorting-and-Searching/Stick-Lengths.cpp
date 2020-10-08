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
    
    int n;
    cin >> n; 
    lli arr[n]; 
    for (int i=0; i<n; ++i){
        cin >> arr[i];
    }          
    sort(arr, arr+n);
    // The idea is the find the median after sorting,
    // As the sum of distance from all the points to the medain will be minimized.
    int median = arr[n/2];
    lli cost = 0; 
    for (int i = 0; i < n; i++) {
        cost += abs(median - arr[i]);
    }
    cout << cost;

    return 0;
}

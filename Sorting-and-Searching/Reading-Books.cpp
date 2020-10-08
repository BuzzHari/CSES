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
    
    lli sum = 0;
    lli arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum+=arr[i];
    }

    sort(arr, arr+n);

    cout << max(sum, 2*arr[n-1]);

    return 0;
}



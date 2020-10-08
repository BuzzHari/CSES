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
    ar<int,2> a[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    
    sort(a, a+n);

    lli reward=0, time=0;

    for (int i = 0; i < n; ++i) {
        time+=a[i][0];
        reward+=a[i][1] - time;
    }

    cout << reward;
    return 0;
}



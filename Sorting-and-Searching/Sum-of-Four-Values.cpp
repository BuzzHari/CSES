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
    
    int n, x;
    cin >> n >> x;
    ar<int, 2> arr[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i][0], arr[i][1] = i;
    
    sort(arr, arr+n);

    for (int i = 0; i < n; ++i) {
        lli x2 = x - arr[i][0];
        for (int j = i+1; j < n; ++j) {
            lli x3 = x2 - arr[j][0];
            for (int k = j+1, l = n -1; k<l; ++k) {
                while(k<l && arr[k][0]+arr[l][0] > x3)
                    --l;
                if (k<l && arr[k][0]+arr[l][0] == x3) {
                    printf("%lli %lli %lli %lli\n", arr[i][1]+1, arr[j][1]+1, arr[k][1]+1, arr[l][1]+1);
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}



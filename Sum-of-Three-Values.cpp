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
    ar<int,2> arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; ++i) {
        lli a1 = x - arr[i][0];
        for (int j = i+1, k = n-1; j < k; ++j) {
            while(j<k && arr[j][0]+arr[k][0] > a1)
                --k;
            if (j<k && arr[j][0] + arr[k][0] == a1){
                cout << arr[i][1]+1 << " " << arr[j][1]+1 << " " << arr[k][1]+1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}



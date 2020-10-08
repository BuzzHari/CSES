#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>

// Defines for some data types. 
#define ui unsigned int
#define uli unsigned long int
#define ulli unsigned long long int
#define li long int
#define lli long long int

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    
    int pair_count = 0;
    for (int i = 0, j=n-1; i < j;) {
        
        while(i<j && arr[i]+arr[j] > x)
            --j;
        if (i>=j)
            break;
        ++pair_count;
        ++i; --j;
    }
    cout << n-pair_count;

    return 0;
}

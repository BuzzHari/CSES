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
#define ll long long int
#define ar array

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

int main() {
   
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    ll maxsum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i], maxsum+=arr[i];
    }

    ll lo = 0, hi = maxsum;
    ll ans = 0; 
    // The idea is to use binary search to find the optmial sum. 
    // Create groups when the sum of the group increases the mid value,
    // If the number of groups created is more than 'k', check the right side.
    // If the number of groups created is equall or less than 'k', 
    // the current mid may be one solution, check left for a better solution.
    // In the end we'll be left with the best solution. 
    while(lo <= hi) {
        
        ll mid = lo + (hi-lo)/2;
        ll sum = 0;
        ll groups = 0;
        for (int i = 0; i < n; ++i) {

            if (arr[i] > mid) {
                groups = k+1;
                break;
            }

            if (sum+arr[i] > mid) {
                ++groups;
                sum = 0;
            }
            sum += arr[i];
        }
        if (sum > 0)
            ++groups;

        if (groups <= k) {
            ans = mid;
            hi = mid-1;
        }
        else 
            lo = mid+1;
    }
    cout << ans;
    return 0;
}



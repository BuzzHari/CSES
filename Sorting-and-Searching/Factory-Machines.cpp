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
    
    ll n, t;
    cin >> n >> t;

    ll a[n];

    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    
    ll lo = 0, hi = 1e18;
    ll ans = 0; 
    while (lo<=hi) {
        ll mid = lo + (hi-lo)/2; 
    
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum +=  mid/a[i];

            if (sum >= t)
                break;
        }

        if (sum >= t) {
            ans = mid;
            hi = mid-1;
        }
        else  {
            lo = mid+1; 
        }
    }
    cout << ans<< "\n";
    return 0;
}



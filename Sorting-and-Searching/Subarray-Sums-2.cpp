#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <unordered_map>
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
    
    ll n, x;
    cin >> n >> x;
    ll arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    map<ll,ll> hmap;
    ll sum = 0;
    hmap[0]=1 ;
    ll cnt = 0;
    // The idea is store the cumlative sum frequency in a map.
    // So if the array is: 2,4,1,2,7
    // The cumulative sum for each index will be 0,2,6,7,9,16.
    // For ex. for x=7. at i = 2, the cumlative sum = 7, x-7 = 0, 0 is present in map with count =1.
    // at i = 2, cumlative sum = 9, x-9 = 2, 2 is present in the map with count=1.
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        cnt += hmap[sum-x];
        ++hmap[sum];
    }
    cout << cnt;

    return 0;
}



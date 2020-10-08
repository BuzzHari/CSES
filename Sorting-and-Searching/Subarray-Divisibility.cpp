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
    
    ll n;
    cin >> n;
    ll arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    map<ll,ll> hmap;
    ll sum = 0;
    hmap[0]=1 ;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum+arr[i]%n+n)%n;
        cnt += hmap[sum];
        ++hmap[sum];
    }
    cout << cnt;

    return 0;
}



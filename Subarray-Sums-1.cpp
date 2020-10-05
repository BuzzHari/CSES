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
    
    ll n, x;
    cin >> n >> x;

    ll arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    } 
    int cnt = 0;
    ll sum = 0;
    // As the numbers were positive the sliding window method works here.
    for (int i = 0,j=0; i < n;) {
        while (j < n && sum < x){
            sum += arr[j];
            ++j;
        }            
        if (sum == x) 
            ++cnt;
        sum-=arr[i];
        ++i;
    }
    cout << cnt;
    return 0;
}



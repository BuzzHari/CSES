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
    ar<int,2> arr[n];
    multiset<int> q;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i][1] >> arr[i][0];
    }

    sort(arr, arr+n);
    
    int count = 0;
    // The idea is same as the Room Allocation problem. 
    for (int i = 0; i < n; ++i) {
        //for (int x: q)
            //cout << x << " ";
        //cout << "\n";
        
        auto it = q.lower_bound(arr[i][1]+1);
        if (it != q.begin()) {
            --it;
            q.erase(it);
            ++count;
            q.insert(arr[i][0]);
        }
        else if (q.size() < k) {
            ++count;
            q.insert(arr[i][0]);
        }
    }
    cout << count;
    return 0;
}



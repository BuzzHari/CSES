#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <array>
#include <map>
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

    map<int, int> arr;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if (arr.find(x-a) != arr.end()) {
            cout << arr[x-a]+1 << " " << i+1;
            return 0;
        }
        arr[a] = i;
    }
   
    cout << "IMPOSSIBLE\n";

    return 0;
}

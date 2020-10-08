#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
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

    int n, m;
    cin >> n >> m;
    
    set<pair<int, int>> arr;
     
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.insert(make_pair(a,i));
    }
    
    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        // Lower bound for one element higher. 
        set<pair<int, int>>::iterator it = arr.lower_bound({t+1,INT_MIN});
        
        // If it's not the first element, the answer is one before. 
        if (it != arr.begin()) {
            --it;
            cout << (*it).first << "\n";
            arr.erase(it);
        }
        else 
            cout << "-1\n";
    }
    return 0;
}

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
    
    int n;
    cin >> n;
    vector<int> towers;
    int a;
    //cout<<"Input "<<a<<"\n";
    for (int i = 0; i < n; ++i) {
        cin >> a;
        
        // Here the upper_bound works becuse, the vector will be sorted,
        // as the elementes lower than the bottom get stacked and the element which
        // is greater than all the bottom elements from a new base. 
        auto it = upper_bound(towers.begin(), towers.end(), a);
        if (it == towers.end())
            towers.push_back(a);
        else 
            *it = a;
    }
    cout << towers.size();
    return 0;
}

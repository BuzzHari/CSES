#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <climits>

using namespace std;

// Defines for some data types. 
#define ll long long int
#define uint unsigned int
#define ar array

// Macors for some utility function. 
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(a,b) (a) < (b) ? (a) : (b)

const uint MOD =  1000000000+7;

int main() {
    
    int n;
    cin >> n;
    

    // This is another 0-1 knapsack problem.
    // The idea is the same as the Book Shop problem.
    // Keep track of all the sums for the first 'i' coins. 
    set<int> distinct_sums;
    int coin, sum;
    vector<int> temp;
    cin >> coin;
    distinct_sums.insert(coin);
    for (int i = 1; i < n; ++i) {
        cin >> coin;
        for (auto it = distinct_sums.begin(); it!=distinct_sums.end(); ++it) {
            sum = *it + coin;
            temp.push_back(sum);
        }
        distinct_sums.insert(coin);
        distinct_sums.insert(temp.begin(), temp.end());
        temp.clear();
    }

    cout << distinct_sums.size() << "\n";
    for (auto x: distinct_sums)
        cout << x << " ";

    return 0;
}



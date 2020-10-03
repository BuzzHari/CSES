#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
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

    li arr[n];

    for (int i = 0; i < n; ++i) 
        cin >> arr[i];

    li curr = 0, exec = INT_MIN;  
   
    int neg_flag = 1;
    
    for (int i = 0; i < n; ++i) {
        curr += arr[i];
        exec = max(exec, curr);
        if (curr <  0)
           curr = 0;

        if (arr[i] > 0) 
            neg_flag = 0; 
            
    }
    if (neg_flag)
        cout << exec;
    else  
        cout << max(exec,curr);
    return 0;
}

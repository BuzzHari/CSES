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
    
    int arr[n], st[n];
    int top = -1;

    // The idea here is to use stacks.
    // Pop from stack untill the top is greater than the current element.
    // If anything is remaining in the stack, the top will be the ans
    // else print 0 i.e. no ans;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        while(top != -1 && arr[st[top]] >= arr[i])
            --top;
        if (top != -1)
            cout << st[top]+1 << " ";
        else 
            cout << 0 << " ";

        st[++top] = i;
    }

    return 0;
}



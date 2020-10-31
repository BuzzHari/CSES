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
    
    int n, x; 
    cin >> n >> x;

    // This problem is also called a 0-1 knapsack problem. 
    // The ideas here is basically to track of the maximum number of pages 
    // which could be bought for all price till X only buying the first 'i' books. 
    // 
    // max_pages[j] keeps track of the maximum number of pages which can be bought for 'j' price.
    //
    // Our dp relation: max_pages[j] = max(max_pages[j], page_books[i] + max_pages[j-price_books[i]])
    // For Ex:
    //  price_books (i): 4 8  5 3
    //  page_books  (i): 5 12 8 1
    //
    //  So for i = 0. i.e book with price = 4. 
    //  Our max_pages[j] will look like:
    //  
    //  j -> 0 1 2 3 4 5 6 7 8 9 10
    //       0 0 0 0 5 5 5 5 5 5 5
    //  
    //  now, for i = 1. i.e book with price = 8.
    //  Our max_pages[j] will look like:
    //  j -> 0 1 2 3 4 5 6 7 8  9  10
    //       0 0 0 0 5 5 5 5 12 12 12
    //  
    //  now, for i = 2. i.e book with price = 5 
    //  Our max_pages[j] will look like
    //  j -> 0 1 2 3 4 5 6 7 8  9  10
    //       0 0 0 0 5 8 8 8 12 13 13 
    //  
    //  now, for i = 3. i.e book with price = 3 
    //  Our max_pages[j] will look like
    //  j -> 0 1 2 3 4 5 6 7 8  9  10
    //       0 0 0 1 5 8 8 8 12 13 13
    //
    //  max_pages[10] = 10.
   
    int price_books[n], page_books[n];

    for (int i = 0; i < n; ++i)
        cin >> price_books[i];
    for (int i = 0; i < n; ++i)
        cin >> page_books[i];

    int max_pages[x+1] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= price_books[i]; --j) {
            max_pages[j] = max(max_pages[j], page_books[i] + max_pages[j - price_books[i]]);
        }
    }

    cout << max_pages[x];
    return 0;
}



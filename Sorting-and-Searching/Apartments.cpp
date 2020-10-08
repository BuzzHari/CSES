#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
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

    int n, m, k;
    cin >> n >> m >> k;
    int a[n], s[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> s[i];

    sort(a, a+n);
    sort(s, s+m);

    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while(j < m && s[j] < a[i]-k)
            j++;
        
        if(j < m && s[j] <= a[i]+k)
            count++, j++;

    }
    cout << count;


    return 0;
}

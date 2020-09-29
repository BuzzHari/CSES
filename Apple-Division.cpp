#include <iostream>
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
    
    li n;
    scanf("%ld\n", &n);
    li arr[n];
    
    lli sum  = 0;
    
    for (lli i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        sum+=arr[i];
    }

    lli min = INT_MAX;
    lli sub_sum = 0;
    
    for (lli i = 0; i < 1<<n; i++) {
        
        sub_sum = 0;
        for (lli j = 0; j < n; j++){
            if (i & 1<<j) 
                sub_sum += arr[j];
        }
        lli curr = abs((sum - sub_sum) - sub_sum);
        min = MIN(min, curr);
    }
    printf("%lld\n", min);

    return 0;
}

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
#define MAX(a,b) (a) > (b) ? a : b
#define MIN(a,b) (a) < (b) ? a : b

using namespace std;

/*
 *int main() {
 *    
 *    int n, a, b; 
 *    cin >> n >> a >> b;
 *    
 *    ll arr[n];
 *    for (int i = 0; i < n; ++i)
 *        cin >> arr[i];
 *
 *    ll curr_sum=-1e18, exec_sum=-1e18;
 *    int len = 0;
 *    int gstart = -1, start = -1, end = -1;
 *    for (int i = 0; i < n; ++i) {
 *        
 *        if (arr[i] > curr_sum+arr[i]) {
 *            curr_sum = arr[i];
 *            start = i;
 *        }
 *        else  {
 *            curr_sum = curr_sum+arr[i];
 *        }
 *        if (curr_sum > exec_sum) {
 *            gstart = start; 
 *            end = i;
 *            len = end-gstart+1;
 *            if (len >=a && len <=b)
 *                exec_sum = MAX(exec_sum,curr_sum);
 *            else if (len > b) {
 *                curr_sum = arr[i];
 *                exec_sum = MAX(exec_sum,arr[i]);
 *                start = i;
 *            }
 *        }
 *        
 *    
 *    }     
 *    //cout << gstart << " "<< end << "\n";
 *    cout << exec_sum;
 *
 *    return 0;
 *}
 */

/*
 * The idea is just to calculate the prefix sum of the array.
 * So in generall to caluclate the maximun subarray sum using a prefix array is 
 * to keep track of the maximum of current_prefix_sum - min_prefix_sum_so_far.
 *
 * So applying the same logic here, we keep track of min_prefix_so_far in the range using 
 * a set. And just keep track of the maximum of the current_prefix_sum - min_prefix_sum_in_set.
 *
 * When out of range, erase the old prefix sum, basically sliding window technique. 
 *
 * The above bs you see attempt to solve it by modifying Kadane's algorithm. Wasn't successfull as
 * few test cases weren't passing. 
 */


int main()  {
    int n, a, b;
    cin >> n >> a >> b;
    ll arr[n+1] = {0};
    for (int i = 0; i < n; ++i)
        cin >> arr[i+1], arr[i+1]+=arr[i];
    
    set<ar<ll,2>> s;
    ll ans = -1e18;
    for (int i = 0; i <= n; ++i) {

        // Inserting the prefix i-a. 
        if (i >= a)
            s.insert({arr[i-a], i-a});
        
        // Check for max sum in the range using the smallest prefix sum.
        if (s.size())
            ans = max(ans, arr[i] - (*s.begin())[0]);

        // Removing the old prefix when out of range.
        if (i >= b)
            s.erase({arr[i-b],i-b});
    }        
    cout << ans;
    return 0;
}



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
    int inp; 
    
    // A naive DP idea here is to keep track of the longest increasing subsequence(lis) which ends
    // at an index 'i' where 0 <= i < n. 
    //
    // For ex: 7 3 5 3 6 2 9 8
    // 
    // for i = 0: 
    //  i = 0 is base case so, lis[i] = 1
    //  
    //  7 3 5 6 2 9 8
    //  1
    //
    // for i = 1: 
    //  
    //  We check for all 'j' < 'i', and see if arr[j] can be extened.
    //  We keep track of the maxium lenght, and update lis[i] = max_found, 
    //  if nothing can be extened, then lis[i] = 1.
    //  So here lis[1] = 1, and 3 can't extend 7.
    //  
    //  7 3 5 6 2 9 8
    //  1 1
    //
    //  Following the above steps for each index 'i', in the end we get:
    //
    //  7 3 5 6 2 9 8
    //  1 1 2 3 1 4 4
    //
    //  The max of lis array is the length of lis. 
    //
    //  This solution takes O(n^2) complexity, which will time out based on the constraints.
    //
    //  Now to optimize this. 
    //  
    //  In the above example after processing 7 and 3 there are two possible
    //  candidates for a future value 'x' to extend, 7 and 3. 
    //  If 'x', is greater than 7, that means it extend 7 and 3 both, and get the same length. 
    //  If it's, lesser than 7 but greater than 3, it can only extend 3. 
    //  and if it's lesser than both, it extend niether.
    //
    //  We can see that we can remove 7 as a possible canditate,  becuause 3 is a 
    //  much better solution here. 
    //  So what we want to do is, if there are multiple values a1, a2.. and so on as candidates,
    //  and they all give the same length if extended, we just want to keep the minimum value of
    //  them, and remove the rest.
    //
    //  To implement this we could either use a map, 
    //  or keep array which keeps track of minimum ending value of an increasing subsequence.
    //  Lets denote the array with lis[].
    //  So lis[i] = v, means the increasing subsequence of length 'i' ends with a value 'v', which
    //  is minimum of all possible values which could create an increasing subsequen of the same
    //  length. 
    //  
    //  Lets take for ex. 7 3 5 6 2 9 8
    //
    //  Initally lis = []. 
    //
    //  Insert 7, lis = [7]. Here it means that lis of lenght 1 ends with 7.
    //  
    //  Now lets insert 3, 3 can't extend 7, so it can create of lis of 1 by itself, but we
    //  want to keep track of the minimum value which could create a lis of 1. So we replace
    //  7 with 3. 
    //  Our array, lis = [3]
    //
    //  Now lets insert 5, 5 can extend 3 here, so insert 5 into the array. 
    //  Our array, lis = [3, 5]
    //
    //  Now lets insert 6, 5 can extend 3 and 5, so lets insert it into the array. 
    //  Our array, lis = [3, 5, 6]
    //
    //  Now lets insert 2, 2 can't extend any of the values, so it creates an lis of length 1,
    //  but right we have 3 there, so replace 3 with 2. 
    //  Our array, lis = [2, 5, 6]
    //  
    //  Now lets insert 9, 9 can extend all the values present, so lets insert it into the array.
    //  Our array, lis = [2, 5, 6, 9]
    //
    //  Now lets insert 8, 8 can extend 2, 5, 6, creating an lis of lenght 4, but we have 9 there,
    //  so replace 9 with 8.
    //  Our array, lis = [2, 5, 6, 8]
    //
    //  The length of this array is the answer. 
    //
    //  The observation here we can make is that, the array will be in a sorted order, 
    //  so we could just use binary search to find where to insert the new value. 
    //  In C++, we can easily do this using lower_bound(), as it returns a value equal to or 
    //  greater than it. Or end() if it's greater than all the elements present. 

    vector<int> longest_len;
    for (int i = 0; i < n; ++i) {
        cin >> inp;

        auto it = lower_bound(longest_len.begin(), longest_len.end(), inp);
        if (it == longest_len.end())
            longest_len.push_back(inp);
        else 
            *it = inp;
    }
    
    cout << longest_len.size();
    return 0;
}



#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <climits>
#include <stack>

// Defines for some data types. 
#define li long int
#define lli long long int
#define ar array

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

/*
 *int main() {
 *    
 *    multimap<int,pair<int,int>> custs;
 *
 *    int n;
 *    cin >> n;
 *
 *    for (int i = 0; i < n; ++i) {
 *        int a;
 *        int b;
 *        cin >> a >> b;
 *        custs.insert({2*a, {1,i}});
 *        custs.insert({2*b+1,{-1,i}});
 *    }
 *
 *    int c = 0;   
 *    int ans  = -1;
 *    stack<int> free_rooms;
 *    set<ar<int,2>> assigned;
 *    map<int,int> rooms;
 *    for (auto it = custs.begin(); it != custs.end(); ++it) {
 *        c += it->second.first;
 *        ans = MAX(ans, c);
 *        if (it->second.first == 1) { 
 *            if (free_rooms.empty()) {
 *                free_rooms.push(c);
 *            }
 *
 *            assigned.insert({it->second.second, free_rooms.top()});
 *            rooms[it->second.second] = free_rooms.top();
 *            free_rooms.pop();
 *        }
 *        if (it->second.first == -1) {
 *            auto temp = assigned.lower_bound({it->second.second,INT_MIN});
 *            free_rooms.push((*temp)[1]);
 *            assigned.erase(temp);
 *        }
 *
 *    }
 *    cout << ans << "\n";
 *    for(auto x: rooms)
 *        cout << x.second << " ";
 *    return 0;
 *}
 */

// This is much better solution. The idea is to sort times by end time. 
// Insert the endtime and the room allocated in a set. 
// Search for the lower bound in the set based on the start time of the new entry.
// The entry in the set before the lower bound must have left, so assign that room the new guy.

int main() {
    int n;
    cin >> n;

    int ans[n];

    ar<int, 3> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }

    sort(a, a+n);

    set<ar<int,2>> s;
    for (int i = 0; i < n; ++i) {

        auto it = s.lower_bound({a[i][1]});
        if (it != s.begin()) {
            --it;
            ans[a[i][2]] =  (*it)[1];
            s.erase(it);
        }
        else 
            ans[a[i][2]] = s.size();

        s.insert({a[i][0], ans[a[i][2]]});
    }
    // All the rooms will be allocated by the end.
    cout << s.size() << "\n";

    for (int i = 0; i < n; ++i)
        cout << ans[i]+1 << " ";
}




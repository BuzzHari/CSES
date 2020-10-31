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
#define ll long long 
#define uint unsigned int
#define ar array

// Macors for some utility function. 
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(a,b) (a) < (b) ? (a) : (b)

const uint MOD =  1000000000+7;

int main() {
    
    int n;
    cin >> n;
    ar<ll, 3> projects[n];
    for (int i = 0; i < n; ++i) {
        cin >> projects[i][1] >> projects[i][0] >> projects[i][2];
    }

    sort(projects, projects+n);

    // The idea here is to sort based on the end times. 
    // Now we keep track of the max reward for each project and their end day, this could be done
    // by using a set or a map. 
    // So the base case is that project ending at day 0 gives 0 reward. 
    //
    // Starting of from the sorted input. For the starting day we find an entry in the set, 
    // such that the end day of that project is lesser than the start day of the current project, 
    // if we can find such an entry this mean we could do the current project after that project. 
    //
    // Once we find such entry, we check if the new max reward is greater than the current one, 
    // if so we update the max reward, and insert this project's end day with the updated 
    // max reward. 
    // Doing this for all the entries in the sorted array we'll get the max reward possible by 
    // the end. 
    //
    // Complexity: O(nlogn)
    
    set<ar<ll, 2>> end_times;
    ll max_reward = 0;
    end_times.insert({0,0});
    for (int i = 0; i < n; ++i) {
        
        auto it = end_times.lower_bound({projects[i][1]});
        --it;
        
        max_reward = max(max_reward, projects[i][2] + (*it)[1]);

        end_times.insert({projects[i][0], max_reward});
    }

    cout << max_reward;
    return 0;
}



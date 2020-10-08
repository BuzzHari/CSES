#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <climits>
#include <iterator>


// Defines for some data types. 
#define li long int
#define ll long long int
#define ar array

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

//int main() {
    
    //ll n, k;
    //cin >> n >> k;
    //cin >> n; 
    //ll arr[n];
    //for (int i = 0; i < n; ++i) {
        //cin >> arr[i];
    //}

    //multiset<ll> nums;
    //int j = 0;
    //while(j < k)
        //nums.insert(arr[j++]);

    //for (int i = j; i < n; ++i) {
        
        //auto it = nums.begin();
        //if (k%2)
            //advance(it, k/2);
        //else 
            //advance(it, k/2-1);
        //cout << *it << " ";
        //nums.erase(nums.find(arr[i-k]));
        //nums.insert(arr[i]);
    //}
    
    //auto it = nums.begin();
    //if (k%2)
        //advance(it, k/2);
    //else 
        //advance(it, k/2-1);
    //cout << *it << " ";
    //return 0;
//}

// Keeps all the element smaller than the elements in the large set.
// Acts as max heap. The elements are accessed from the back. Because the last element in this
// set will the median if the size is equall or greater than the size of large set. 
multiset<int> small;
// If the size of large set is greater, then the first element will be the medain.
// Acts like a min heap. 
multiset<int> large;

void fix() {
    // This fixes the size of both the sets.
    // Basically this condition has to be maintained large.size()-small.size <=1
    int size = 1+small.size()+large.size();
    if (large.size() > (size-1)/2) {
        small.insert(*large.begin());
        large.erase(large.begin());
    }
    else if (large.size() < (size-1)/2) {
        large.insert(*--small.end());
        small.erase(--small.end());
    }
}

void add(int elem) {
    // Adds into the set.  
    if (large.size() && elem >= *large.begin())
        large.insert(elem);
    else
        small.insert(elem);
    fix();
}

int getMedain() {
    // Gets the median.
    if (small.size() >= large.size())
        return *--small.end();

    return *large.begin();
}

void remove(int elem) {
    // Remove the the elem.  
    multiset<int>::iterator it; 
    if ((it = large.find(elem)) != large.end()){
        large.erase(it);        
    }
    else if ((it = small.find(elem)) != small.end()) {
        small.erase(it);
    } 
    fix();
}

int main() {
    
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    if (k == 1) {
        for (int x: arr) {
            cout << x << " ";
        }
        return 0;
    }
    // Intiallizing the sets with the first k elements. 
    for (int i = 0; i < k; ++i) {
        small.insert(arr[i]);
    }
    // Add last k/2 elements from the small set to the large set. 
    for (int i = k-1; i >= k/2; --i) {
        large.insert(*--small.end());
        small.erase(--small.end());
    }
    // Using the Window slide method.
    for (int i = k; i < n; ++i) {
        cout << getMedain() << " ";
        remove(arr[i-k]);
        add(arr[i]);
    }
    cout << getMedain() << " ";
}


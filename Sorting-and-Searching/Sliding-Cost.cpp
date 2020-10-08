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
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

multiset<ll> small;
multiset<ll> large;
ll small_sum=0, large_sum=0;

void fix() {
    int size = large.size()+small.size()+1;
    if (large.size() > (size-1)/2) {
        small.insert(*large.begin());
        small_sum += *large.begin();
        large_sum -= *large.begin();
        large.erase(large.begin());
    }
    else if (large.size() < (size-1)/2) {
        large.insert(*--small.end());
        large_sum += *--small.end();
        small_sum -= *--small.end();
        small.erase(--small.end());
    }
}

void add(ll elem) {
    if (large.size() && elem >= *large.begin()) {
        large.insert(elem);
        large_sum+=elem;
    }
    else  {
        small.insert(elem);
        small_sum+=elem; 
    }
    fix();
}

ll getMedian() {

    if (small.size() >= large.size())
        return *--small.end();
    
    return *large.begin();
}

void remove(ll elem) {
    
    multiset<ll>::iterator it;
    if ((it = large.find(elem)) != large.end()) {
        large_sum -= *it; 
        large.erase(it);
    }
    else if ((it = small.find(elem)) != small.end()) {
        small_sum -= *it;    
        small.erase(it);
    }
    fix();
}


int main() {

    int n, k;
    cin >> n >> k;
    
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (k == 1) {
        for (int x: arr)
            cout << 0 << " ";
        
    }
    else {
        for (int i = 0; i < k; ++i)  {
            small_sum += arr[i];
            small.insert(arr[i]);
        }
        for (int i = k-1; i >= k/2; --i){
            large.insert(*--small.end());
            large_sum += *--small.end();
            small_sum -= *--small.end();
            small.erase(--small.end());
        }

        ll med;
        for (int i = k; i < n; ++i) {
            med = getMedian();
            //printf("LS %lld SS %lld MED %lld\n", large_sum, small_sum, med);
            cout << (small.size()*med-small_sum) + (large_sum - large.size()*med)  << " ";
            remove(arr[i-k]);
            add(arr[i]);
        }
        med = getMedian();
        //printf("LS %lld SS %lld MED %lld\n", large_sum, small_sum, med);
        cout << (small.size()*med-small_sum) + (large_sum - large.size()*med)  << " ";
    }


    return 0;
}



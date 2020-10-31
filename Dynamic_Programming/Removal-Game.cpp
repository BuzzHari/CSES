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
    
    ll arr[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // The idea behind this problem is that to keep track of the max sum 
    // Player 1 can get if we start of subarray of size 1, 2, 3..n.
    //
    // Lets say we have a1, a2, a3, a4, a5....aN.
    // If we choose an subarray starting from index 'i' to index 'j'.
    //
    // And let, Score(i,j) be the maximum score player 1 can get in the subarry ij. 
    //
    // Player 1 will have two options:
    //  
    //  Option 1: He can choose 'i', so that will leave player 2 with (i+1,j)
    //            to choose from. So player 2 can either choose 'i+1' or 'j'.
    //            Which will leave 2 options for player 1 on his 
    //            next turn accourdingly:
    //
    //              Ai + Score(i+1, j-1) OR,
    //              Ai + Score(i+2, j). 
    //
    //              We will have to choose min(Score(i+1, j-1), Score(i+2, J)) because
    //              player 2 also plays optimally and he'll always choose the one which will
    //              be max for him. 
    //
    //              So, it becomes
    //
    //             score1 =  Ai + min(Score(i+1, j-1), Score(i+2, j)).
    //
    // Option 2: Similarly if he choose 'j', 
    //              
    //             the equation will look like:
    //
    //             score2 = Aj + min(Score(i+1, j-1_, Score(i, j-2));
    //
    // And, we want to maximize Player1's score, so we choose the max between score1, score2.
    // i.e 
    //     Score[i][j] = max(score1, score2);
    //  
    // Notic for cases j > i, it's not a valid subarray. so those values will be zero. 
    
    ll score[n][n];
    memset(score, 0, sizeof(ll)*(n*n));

    ll x, y, z; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0, k = i; k < n; ++j, ++k) {
            x = 0; y = 0; z = 0;
            if (j == k)
                score[j][k] = arr[j];
            else {

                if ( k-1 >= 0 && j+1 < n) 
                    x = score[j+1][k-1];

                if (j+2 < n)
                    y = score[j+2][k];

                if (k-2 >= 0)
                    z = score[j][k-2];

                score[j][k] = max(arr[j] + min(x,y),  arr[k]+min(x,z));

            }
        }
    }

    cout << score[0][n-1];


    return 0;
}



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

#define N 7 

int path = 0;
string str;

int canMove(char board[N*N], int row, int col) {

    //Checking if already visited.
    return (row >= 0 && row < N  && col >= 0 && col < N && !(board[row*N+col]));

}

void solve(char board[N*N], int row, int col, int index=0) {
    //printf("row: %d, col: %d\n", row, col); 
    if (row == N-1 && col == 0) {
        // checking if all the nodes were visited.
        if (index == 48)
            ++path;
        return;
    }

    board[row*N+col] = 1;
    
    // Go Down if possible.
    if (str[index] == '?' || str[index] == 'D') {
        if (canMove(board, row+1, col)) {
            if (!(!canMove(board, row+2, col) && canMove(board, row+1, col-1) && canMove(board, row+1, col+1)))
            solve(board, row+1, col, index+1);
        }
    }
    // Go Right if possible.
    if (str[index] == '?' || str[index] == 'R') {
        if (canMove(board, row, col+1)) {
            if (!(!canMove(board, row, col+2) && canMove(board, row-1, col+1) && canMove(board, row+1, col+1)))
            solve(board, row, col+1, index+1);
        }
    }

    // Go Up if possible.
    if (str[index] == '?' || str[index] == 'U') {
        if (canMove(board, row-1, col)) {
            if (!(!canMove(board, row-2, col) && canMove(board, row-1, col-1) && canMove(board, row-1, col+1)))
            solve(board, row-1, col, index+1);
        }
    }

    // Go left if possible.
    if (str[index] == '?' || str[index] == 'L') {
        if (canMove(board, row, col-1)) {
            if (!(!canMove(board, row, col-2) && canMove(board, row-1, col-1) && canMove(board, row+1, col-1)))
            solve(board, row, col-1, index+1);
        }
    }
    
    board[row*N+col] = 0;
}

int main() {
    
    char board[N*N] = {0};
    
    cin >> str;    
    solve(board, 0, 0, 0);

    printf("%d\n", path);

    return 0;
}

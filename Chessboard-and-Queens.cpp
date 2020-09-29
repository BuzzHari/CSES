#include <iostream>
#include <vector>
#include <string.h>
#include <climits>

// Defines for some data types. 
#define ui unsigned int
#define uli unsigned long int
#define ulli unsigned long long int
#define li long int
#define lli long long int

// Defines for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b


using namespace std;

void printBoard(char board[8][8]) {
    
    static int count = 1;
    printf("%d.\n", count);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) { 
            printf("%c   ", board[i][j]);
        }
        printf("\n");
    }
    count++ ;
}

int isSafe(char board[8][8], int row, int col) {
    
    if (board[row][col] == '*')
        return 0;

    // checking if row is safe. 
    for (int i = 0; i < col; i++) {
        if (board[row][i] == '1')
            return 0;
    }

    // checking if upper left diagonal is safe.
    for (int i = row, j = col; i >= 0 && j >=0 ; i--, j--) {
        if (board[i][j] == '1')
            return 0;
    }
    
    // checking if lower left diagonal is safe.
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == '1')
            return 0;
    }
    
    // If reaches till here then it's safe.
    return 1;
}

li count = 0;

void solve(char board[8][8], int col) {

    if (col >= 8) {
        //printBoard(board);
        count++;
        return;
    }

    for (int i = 0; i < 8; i++) {

        if (isSafe(board, i, col) == 1) {
            board[i][col] = '1';

            solve(board, col+1);

            board[i][col] = '.';
        }
    }
}

int main() {
    
    char board[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1s", &board[i][j]);
        }
    }
    
    solve(board,0);
    printf("%ld\n", count);

    return 0;
}

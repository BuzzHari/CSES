/*
 *  Counting trailing zeros end of factorail. 
 *  This idea is just to count the number of 5s in the numbers. 
 */
#include <iostream> 
#include <math.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    int count = 0;
    int temp;
    while (n >= 5) {
        temp = ceil(n/5);
        count+=temp;
        n = temp;
    }
    printf("%d\n", count);
}

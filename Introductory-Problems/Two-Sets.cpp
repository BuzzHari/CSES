/*
 * Spliting numbers from 1-n, into sets of equal sum. 
 * 
 * If sum is even and n is odd, place 1,2 in first set and 3 in second,
 * and from 4, apply gauss method, i.e. the first and last in one set, then the second and second
 * last in another set and so on. 
 * This case can be basically be represented as n=3 (mod 4). 
 *
 * If sum is even and n is also even, then straight up apply the gauss method. 
 */
#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    long long int sum = (n*(n+1))/2;

    if (sum % 2) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
        if (n % 2 == 0) { 
            printf("%d\n", n/2);
            for(int i = 1, j = n; i <= n/2 ; i+=2, j-=2)
                printf("%d %d ", i, j);

            printf("\n%d\n", n/2);
            for(int i = 2, j = n-1; i <= n/2 ; i+=2, j-=2)
                printf("%d %d ", i, j);
            printf("\n");
        }
        else {
            printf("%d\n", 2+(n-3)/2);
            printf("1 2 ");
            for(int i = 4, j = n; i <= n/2+1; i+=2, j-=2)
                printf("%d %d ", i, j);
            printf("\n%d\n", 1+(n-3)/2);
            printf("3 ");
            for(int i = 5, j = n-1; i <= n/2+2; i+=2, j-=2)
                printf("%d %d ", i, j);
            printf("\n");
        }
    }
    return 0;
}

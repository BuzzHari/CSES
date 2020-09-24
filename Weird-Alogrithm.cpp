#include <iostream>

int main() { 
    
    long long int n;
    scanf("%lld", &n);
    printf("%lld ", n);
    while(n > 1) {
        if (n % 2) {
            n = n*3 + 1;
            printf("%lld ", n);
        }
        else {
            n = n / 2;
            printf("%lld ", n);
        }
    }
    printf("\n");
    return 0;
}

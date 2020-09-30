#include <iostream>

using namespace std;

int main() {
    
    long long int n; 
    scanf("%lld", &n);

    long long int sum = 0;
    int num;
    
    for( int i = 0; i<n-1; i++) {
        scanf("%d", &num);
        sum += num;
    }

    long long int actual_sum = 0;
    if (n % 2) 
        actual_sum = n * (n+1)/2;
    else
        actual_sum = n/2 * (n+1);


    printf("%lld\n", actual_sum - sum);
    return 0;
}

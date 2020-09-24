#include <iostream>

using namespace std;

int main() {

    int n;
    
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    long long int turns = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            turns = turns + arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    
    printf("%lld\n", turns);

}

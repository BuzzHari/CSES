#include <iostream>

using namespace std;

#define MOD (1000000000+7)

int main() {

    int n;
    cin >> n;
    long int ans = 1;

    for (int i = 1; i<= n; i++) {
        ans = (ans * 2) % MOD;
    }
    printf("%ld\n", ans);
}

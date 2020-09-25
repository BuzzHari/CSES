#include <iostream>
using namespace std;


int main() {

    int n;
    cin >> n;
    
    long long int ans;
    for(long long int i = 1; i<=n; i++) {
            
        ans = ((i*i)*(i*i - 1))/2 - 4*(i-1)*(i-2);
        printf("%lld\n", ans);
    }
    return 0;
}

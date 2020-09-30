#include <iostream>
#define MAX(a,b) a > b? a: b
#define MIN(a,b) a < b? a: b
using namespace std;
int main() {
    int n; 
    cin >> n;
    long int a, b;
    while (n--) {
        cin >> a >> b;
        
        long int max = MAX(a,b);
        long int min = MIN(a,b);

        if (max > min*2)
            printf("NO\n");
        else if( (max+min) % 3 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    } 
    return 0;
}

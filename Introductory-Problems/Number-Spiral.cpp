#include <iostream>

using namespace std;

#define MAX(x,y) x > y ? x: y

int main() {
    
    int t;
    scanf("%d", &t);
    
    long int x, y;
    while(t--) {
        scanf("%ld %ld", &x, &y);

        long int max = MAX(x,y);
        long int ans;
        if (x <= y) {
            if (y % 2)
                ans = y*y - (x-1);
            else 
                ans = y*y - (y*2 - (x+1));
        }
        else  {
            if ( x % 2) 
                ans = x*x - (x*2 - (y+1));
            else 
                ans = x*x - (y-1);
        }

        printf("%ld\n", ans);
    }
    return 0;
}

#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    
    if ( n==2 || n==3 )
        printf("NO SOLUTION\n");

    //Print all odd numbers first and the all even numbers. 
    
    else if ( n == 4)
        printf("3 1 4 2\n");
    else {
        
        int i = 1;
        while (i <= n ) {
            printf("%d ", i);
            i+=2;
        }

        i = 2;
        while (i <= n ) {
            printf("%d ", i);
            i+=2;
        }
    }


    return 0;
}


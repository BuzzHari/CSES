#include <iostream>
#include <string>

using namespace std;


int main() {
    
    string seq;
    cin >> seq;
    
    int count = 0;
    int max_count = 0;
    char current;
    
    current = seq[0];
    for (int i = 0; i < seq.size(); i++) {
        
        if (seq[i] == current)
            count++;
        else  {
            if (count > max_count)
                max_count = count;
            count = 1;
            current = seq[i];
        }
    }

    if (count > max_count)
        max_count = count;
    printf("%d\n", max_count);
    return 0;
}

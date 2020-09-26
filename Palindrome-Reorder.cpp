#include <iostream>
#include <string.h>

using namespace std;

int main() {
    
    
    string letters;
    cin >> letters;

    long int freq[26] = {0};

    for (int i = 0; i < letters.size(); i++) {
        freq[letters[i] - 'A']+=1;
    }
    
    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2)
            odd_count+=1;
        if (odd_count > 1) {
            printf("NO SOLUTION\n");
            exit(0);
        }
    }

    string even = "";
    string odd = "";

    for (int i = 0; i <  26; i++) {
        if (freq[i] % 2 == 0) {
            even.insert(even.end(), freq[i]/2, 'A'+i);
        }
        else  {
            odd.insert(odd.end(), freq[i], 'A'+i);
        }            
    }

    cout << even << odd;
    for (string::const_reverse_iterator it = even.crbegin(); it != even.crend(); ++it)
        cout << *it;
    cout << endl;

}

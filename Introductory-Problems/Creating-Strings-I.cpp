/*
 *  Generating all strings lexicographically. 
 *  i = N-1; 
 *  Find i-1 >= i; --i;
 *  j = N;
 *  Find j-1 <= i-1; --j;
 *  swap(i-1, j-1);
 *  i++, j=N;
 *  while(i < j) swap(i-1, j-1), i++, j--;
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int fact(int n) {
    int res = 1;
    for (int i = 1; i <=n; i++)
        res *= i;
    return res;
}

int countPerms(string letters) {

    int freq[26] = {0};
    for (int i = 0; i<letters.size(); i++)
        freq[letters[i]-'a']+=1;

    int n = fact(letters.size());
    
    int d = 1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1)
            d *= fact(freq[i]);
    }
    int res = n/d;
    return res;
}

void swap(string& letters, int i, int j) {
    char temp = letters[i];
    letters[i] = letters[j];
    letters[j] = temp;
}


void getNextPerm(string& letters) {
    int i = letters.size()-1;
    // finding the letter which is lesser than the current. 
    // i-1 <= i
    while(letters[i-1] >= letters[i])
        --i;

    int j = letters.size();
    // finding the highest index j to the right of i
    while(letters[j-1] <= letters[i-1])
        --j;

    swap(letters, i-1, j-1);

    j = letters.size();
    i++;
    while (i < j) {
        swap(letters, i-1, j-1);
        i++;
        --j;
    }
}

int main() {
    
    string letters;
    cin >> letters;

    sort(letters.begin(), letters.end());

    int number_of_perms = countPerms(letters);
    printf("%d\n", number_of_perms);
    while(number_of_perms--) {
        cout << letters << endl;
        getNextPerm(letters);
    }
}

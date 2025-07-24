//FormAI DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

int main() {

    char sentence[MAX_LEN];
    int num_vowels = 0, num_consonants = 0, num_spaces = 0, num_digits = 0;
    int len;

    printf("Enter a sentence (maximum length 1000):\n");
    fgets(sentence, MAX_LEN, stdin);

    len = strlen(sentence);

    for (int i=0; i<len; i++) {
        char c = sentence[i];
        if (isalpha(c)) {
            c = tolower(c); // Convert to lowercase
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                num_vowels++; // Count vowels
            } else {
                num_consonants++; // Count consonants
            }
        } else if (isdigit(c)) {
            num_digits++; // Count digits
        } else if (isspace(c)) {
            num_spaces++; // Count spaces
        }
    }

    printf("Number of vowels: %d\n", num_vowels);
    printf("Number of consonants: %d\n", num_consonants);
    printf("Number of spaces: %d\n", num_spaces);
    printf("Number of digits: %d\n", num_digits);

    return 0;
}
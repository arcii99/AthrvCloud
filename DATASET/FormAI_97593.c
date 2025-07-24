//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Welcome to the C Word Frequency Counter!\n");
    
    // initialize variables
    char c;
    int words = 0;
    int freq[26] = {0};

    // prompt user for input
    printf("Please enter your text below:\n");
    while ((c = getchar()) != EOF) {
        if (!isalpha(c)) {
            words++;
        } else {
            c = tolower(c);
            freq[c - 'a']++;
        }
    }

    // print results
    printf("===========================\n");
    printf("Total words entered: %d\n", words);
    printf("Word frequency:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', freq[i]);
    }
    printf("===========================\n");
    
    printf("Thank you for using the C Word Frequency Counter!\n");
    return 0;
}
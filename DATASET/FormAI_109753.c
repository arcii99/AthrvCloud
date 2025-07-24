//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {

    // initialize an array to store the frequency counts of each letter
    int frequency[26] = {0};
    
    // prompt the user to enter a string
    printf("Please enter a string: ");
        
    // read in the user's input
    char input[1000];
    fgets(input, 1000, stdin);

    // loop through each character in the string
    for (int i = 0; i < strlen(input); i++) {

        // convert the character to lowercase
        char c = tolower(input[i]);

        // if the character is a letter, increment its corresponding frequency count
        if (isalpha(c)) {
            frequency[c - 'a']++;
        }
    }

    // print out the results
    printf("Letter Frequency Count:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', frequency[i]);
    }

    return 0;
}
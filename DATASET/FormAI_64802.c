//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

int main() {
    char input[MAX_INPUT_LENGTH]; // input string
    int wordCount = 0; // number of words in input
    int inWord = 0; // boolean, indicates whether we are currently inside a word

    printf("Welcome to the CyberWordCount tool.\n\n");
    printf("Enter your text to count the number of words:\n");

    fgets(input, sizeof(input), stdin); // get input from user

    // loop through each character in input
    for (int i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) { // if character is a space
            inWord = 0; // not in a word
        }
        else if (!inWord) { // if character is not a space and we are not in a word
            inWord = 1; // now in a word
            wordCount++; // increment word count
        }
    }

    printf("\nNumber of words: %d\n", wordCount);

    return 0;
}
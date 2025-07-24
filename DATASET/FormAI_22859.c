//FormAI DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    char input_string[10000], word[MAX_WORD_LENGTH];
    int word_count = 0;

    printf("Welcome to the C Word Count Tool.\n");
    printf("Please enter a paragraph of text to count the number of words in it:\n");

    // get input string
    fgets(input_string, 10000, stdin);

    // loop through input string
    for (int i = 0; i < strlen(input_string); i++) {
        // check if char is space or newline
        if (input_string[i] == ' ' || input_string[i] == '\n') {
            // end word
            word[word_count] = '\0';
            word_count = 0;
            // print word
            printf("%s\n", word);
        }
        else {
            // add char to word
            word[word_count] = input_string[i];
            word_count++;
        }
    }

    printf("\nTotal number of words: %d", word_count);

    return 0;
}
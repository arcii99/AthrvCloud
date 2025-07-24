//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

char* word_reverse(char* word) {
    char tmp;
    int i, j;

    for(i = 0, j = strlen(word) - 1; i < j; ++i, --j) {
        tmp = word[i];
        word[i] = word[j];
        word[j] = tmp;
    }

    return word;
}

int main(void) {
    char input[256]; // user input
    char word[MAX_WORD_LENGTH]; // buffer for current word being read
    int word_idx = 0; // index of next empty slot in word buffer
    int i;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // remove newline character from input
    strtok(input, "\n");

    // iterate through each character in input
    for(i = 0; i < strlen(input); ++i) {
        // if the current character is not a space or punctuation
        if(isalpha(input[i])) {
            // append it to the current word
            word[word_idx++] = tolower(input[i]);
        }
        // if the current character is a space or punctuation
        else {
            // if there is a current word in the buffer
            if(word_idx > 0) {
                // null-terminate the current word
                word[word_idx] = '\0';

                // reverse the current word and print it
                printf("%s ", word_reverse(word));

                // reset the word buffer
                word_idx = 0;
            }
        }
    }

    // if the last character in input is not a space or punctuation
    if(word_idx > 0) {
        // null-terminate the last word and print it
        word[word_idx] = '\0';
        printf("%s", word_reverse(word));
    }

    printf("\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

int main()
{
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_WORDS] = { 0 };
    char input[MAX_WORD_LENGTH];
    char *token;
    int i, j, k, len, count = 0;

    printf("Enter the text:\n");

    // Read in the input
    fgets(input, MAX_WORD_LENGTH, stdin);

    len = strlen(input);

    // Strip out non-alphabetic characters and convert to lowercase
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            input[i] = tolower(input[i]);
        } else {
            input[i] = ' ';
        }
    }

    // Tokenize the input
    token = strtok(input, " ");

    while (token != NULL) {
        // Check if the word is already in the words array
        for (i = 0; i < count; i++) {
            if (strcmp(token, words[i]) == 0) {
                word_count[i]++;
                break;
            }
        }

        // If word is not in the words array, add it
        if (i == count) {
            strcpy(words[count], token);
            word_count[count]++;
            count++;
        }

        token = strtok(NULL, " ");
    }

    // Print out the word count results
    printf("Word Frequency:\n");

    for (i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], word_count[i]);
    }

    return 0;
}
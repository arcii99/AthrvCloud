//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

// Function prototype
void count_words(char *text, char words[MAX_NUM_WORDS][MAX_WORD_LENGTH], int word_count[MAX_NUM_WORDS], int *num_unique_words);

int main() {
    char text[10000];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_NUM_WORDS];
    int num_unique_words = 0;

    // Get input text from user
    printf("Enter the text (maximum 10,000 characters): \n");
    fgets(text, 10000, stdin);

    // Remove newline character from input text
    if ((strlen(text) > 0) && (text[strlen(text) - 1] == '\n'))
        text[strlen(text) - 1] = '\0';

    // Count the words in the input text
    count_words(text, words, word_count, &num_unique_words);

    // Print the frequency of each word
    printf("\nWord Frequency Table:\n");
    for (int i = 0; i < num_unique_words; i++) {
        printf("%-20s %d\n", words[i], word_count[i]);
    }

    return 0;
}

// function definition
void count_words(char *text, char words[MAX_NUM_WORDS][MAX_WORD_LENGTH], int word_count[MAX_NUM_WORDS], int *num_unique_words) {
    char *token;

    token = strtok(text, " "); // Get first token
    while (token != NULL) {
        // Check if the token is already in the words array
        int i;
        for (i = 0; i < *num_unique_words; i++) {
            if (strcmp(token, words[i]) == 0) {
                word_count[i]++;
                break;
            }
        }

        // If token not found, add it to words array and set count to 1
        if (i == *num_unique_words) {
            strcpy(words[*num_unique_words], token);
            word_count[*num_unique_words] = 1;
            (*num_unique_words)++;
        }

        token = strtok(NULL, " "); // Get next token
    }
}
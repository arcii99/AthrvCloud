//FormAI DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read input asynchronously
void read_input(char* input, int* length) {
    printf("Enter a sentence to check for spelling errors (press enter to submit):\n");
    fgets(input, 100, stdin);
    *length = strlen(input);
}

// Function to check for spelling errors asynchronously
void check_spelling(char* input, int length) {
    char* dictionary[10] = {"apple", "banana", "cat", "dog", "elephant", "frog", "giraffe", "horse", "igloo", "jungle"};
    int dictionary_size = 10;
    char* words[20];
    int num_words = 0;

    // Split the input into individual words
    char* token = strtok(input, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Check each word against the dictionary
    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < dictionary_size; j++) {
            if (strcmp(words[i], dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Spelling error: %s\n", words[i]);
        }
    }
}

int main() {
    char input[100];
    int length = 0;

    // Read input asynchronously
    read_input(input, &length);

    // Check spelling asynchronously
    check_spelling(input, length);

    return 0;
}
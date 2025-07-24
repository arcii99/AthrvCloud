//FormAI DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a maximum word length for spam detection
#define MAX_WORD_LENGTH 20

// Define the list of banned words
const char* bannedWords[] = {"lottery", "viagra", "enlarge", "inheritance", "money", "million", "opportunity"};

// Define the function that checks if a word is banned
bool isBanned(char* word) {
    int i;
    for (i = 0; i < 7; i++) {
        if (strcmp(word, bannedWords[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    printf("Welcome to the Spam Detection System!\n");

    // Prompt the user for input
    char input[1000];
    printf("\nEnter a message: ");
    fgets(input, 1000, stdin);

    // Convert input to lowercase
    int i;
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize the input into individual words
    char* word = strtok(input, " ,.?!");

    // Check each word for spam
    int spamCount = 0;
    while (word != NULL) {
        // Check if the word is too long
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("\nError: Word '%s' is too long!\n", word);
            exit(0);
        }

        // Check if the word is banned
        if (isBanned(word)) {
            printf("\nWarning: Word '%s' is banned!\n", word);
            spamCount++;
        }

        // Get the next word
        word = strtok(NULL, " ,.?!");
    }

    // Print the spam count
    if (spamCount > 0) {
        printf("\nThis message contains %d instances of spam!\n", spamCount);
    } else {
        printf("\nThis message is free of spam. Congratulations!\n");
    }

    return 0;
}
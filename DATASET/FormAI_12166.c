//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum length for the input string
#define MAX_LENGTH 1000

// Define structure for each word and how often it appears in the input string
typedef struct {
    char word[50];
    int count;
} WordCount;

// Determine if the given character is a letter or not
int isChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

int main() {
    char input[MAX_LENGTH];
    WordCount wordArr[MAX_LENGTH];
    int i, j, k, count, n = 0;

    // Initialize all the word counts to 0
    for (i = 0; i < MAX_LENGTH; i++) {
        wordArr[i].count = 0;
    }

    // Take string input from user
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Count the frequency of each word in the input string
    for (i = 0; i < strlen(input); i++) {
        if (isChar(input[i])) {
            // If character is a letter, make sure it's uppercase and add it to current word
            input[i] = toupper(input[i]);
            wordArr[n].word[count] = input[i];
            count++;
        } else {
            // If character is not a letter, we've found a new word. Increment count for current word.
            if (count > 0) {
                wordArr[n].word[count] = '\0';
                wordArr[n].count++;
                count = 0;
                n++;
            }
        }
    }

    // Print table of word frequencies
    printf("\nWord Frequencies:\n");
    printf("------------------\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(wordArr[i].word, wordArr[j].word) > 0) {
                // Swap the two elements to order the words alphabetically
                WordCount temp = wordArr[i];
                wordArr[i] = wordArr[j];
                wordArr[j] = temp;
            }
        }
        printf("%-25s: %d\n", wordArr[i].word, wordArr[i].count);
    }

    return 0;
}
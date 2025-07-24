//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// define constant for maximum length of word
#define MAX_WORD_LENGTH 50

// function to count the frequency of words
void countWords() {
    char input[1000];
    int wordCount = 0;
    int c, index = 0;

    // declare an array to hold the words
    char words[500][MAX_WORD_LENGTH];

    printf("Enter text (max 1000 characters):\n");
    while ((c = getchar()) != '\n' && index < 1000) {
        input[index++] = c;
    }
    input[index] = '\0';

    // remove punctuation marks and convert to lowercase
    for (int i = 0; i < strlen(input); i++) {
        if (ispunct(input[i])) {
            input[i] = ' ';
        }
        input[i] = tolower(input[i]);
    }

    // tokenize the input and store the words in the array
    char* token = strtok(input, " ");
    while (token != NULL) {
        strcpy(words[wordCount++], token);
        token = strtok(NULL, " ");
    }

    // get the frequency of each word
    int frequency[wordCount];
    for (int i = 0; i < wordCount; i++) {
        frequency[i] = 1;
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[i]++;
                // mark the word as counted
                strcpy(words[j], "");
            }
        }
    }

    // display the word frequency table
    printf("\nWord frequencies:\n\n");
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(words[i], "") != 0) {
            printf("%-20s %d\n", words[i], frequency[i]);
        }
    }
}

int main() {
    printf("Welcome to the C word frequency counter!\n");
    printf("----------------------------------------\n\n");
    printf("This program will count how many times each word is repeated in a given text.\n\n");
    countWords();
    printf("\nThank you for using the C word frequency counter!\n");
    return 0;
}
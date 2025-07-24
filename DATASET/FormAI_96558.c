//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1000

/* Function prototypes */
int countWords(char *);
void stripPunctuations(char*);

int main() {
    char buffer[MAX_BUF_SIZE];
    printf("Enter a string: ");
    fgets(buffer, MAX_BUF_SIZE, stdin);

    /* Remove punctuations */
    stripPunctuations(buffer);

    /* Count words */
    int wordCount = countWords(buffer);

    printf("Number of words: %d \n", wordCount);
    return 0;
}

/* Function to count the number of words in a given string */
int countWords(char *str) {
    int wordCount = 0;
    char *token;

    /* The delimiter is a space character */
    token = strtok(str, " ");

    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }
    return wordCount;
}

/* Function to remove punctuations */
void stripPunctuations(char *str) {
    int i, j;

    for (i = 0; str[i] != '\0'; i++) {
        /* Check if character is punctuation */
        if (ispunct(str[i])) {
            /* Move all the characters after the punctuation to the left */
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
}
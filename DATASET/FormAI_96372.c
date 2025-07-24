//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000

void incrementWordCount(char *word, int count[], int *totalWords) {
    int i;
    for (i = 0; i < *totalWords; i++) {
        if (strcmp(word, (char *) (count + i * 2)) == 0) {
            (*(count + i * 2 + 1))++;
            return;
        }
    }
    // Word not found, add it to the array
    (void) strcpy((char *) (count + *totalWords * 2), word);
    (*(count + *totalWords * 2 + 1))++;
    (*totalWords)++;
}

int main() {
    int wordCount[MAX_WORD_COUNT][2] = {{0}};
    int totalWords = 0;

    char str[1024];
    printf("Enter a string: ");
    fgets(str, 1024, stdin);

    char *word = strtok(str, " \n");
    while (word != NULL && totalWords < MAX_WORD_COUNT) {
        // Remove any non-alphabetic characters from the word
        int i = 0, j = 0;
        while (i < strlen(word)) {
            if (isalpha(word[i])) {
                word[j++] = tolower(word[i]);
            }
            i++;
        }
        word[j] = '\0';

        // Check if word is not empty after removing non-alphabetic characters
        if (word[0] != '\0') {
            incrementWordCount(word, (int *) wordCount, &totalWords);
        }

        word = strtok(NULL, " \n");
    }

    printf("Word frequency count:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s : %d\n", (char *) (wordCount + i * 2), *(wordCount + i * 2 + 1));
    }

    return 0;
}
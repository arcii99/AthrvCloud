//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

int main() {

    char input[MAX_WORDS];
    char *words[MAX_WORDS];
    int count[MAX_WORDS] = {0};
    int i, j, wordCount;

    printf("Welcome to the Word Frequency Counter Program!\nEnter text for analysis (max 1000 words): ");
    fgets(input, MAX_WORDS, stdin);

    wordCount = 0;
    words[wordCount] = strtok(input, " \n\r\t");

    while(words[wordCount] != NULL && wordCount < MAX_WORDS - 1) {
        wordCount++;
        words[wordCount] = strtok(NULL, " \n\r\t");
    }

    /* Convert all words to lowercase */
    for(i = 0; i < wordCount; i++) {
        for(j = 0; words[i][j]; j++) {
            words[i][j] = tolower(words[i][j]);
        }
    }

    /* Count word frequency */
    for(i = 0; i < wordCount; i++) {
        for(j = 0; j < wordCount; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                count[i]++;
            }
        }
    }

    /* Print word frequency */
    printf("\nWord Frequency:\n");
    for(i = 0; i < wordCount; i++) {
        if(count[i]) {
            printf("%s: %d\n", words[i], count[i]);
        }
    }

    return 0;
}
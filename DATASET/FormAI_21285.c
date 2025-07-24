//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main() {
    printf("Wow, I can't believe I made it this far!\n");
    printf("I never thought I would be writing a program to count word frequencies!\n");
    printf("But here I am, ready to impress the world.\n\n");

    printf("Please enter some text that you would like to count the word frequencies for:\n");
    char input[10000];
    fgets(input, 10000, stdin);

    printf("\nGreat, here are the word frequencies for your input:\n\n");

    char* words[MAX_NUM_WORDS];
    int frequencies[MAX_NUM_WORDS];
    int numwords = 0;
    char* word = strtok(input, " \n\t\r");

    while (word != NULL && numwords < MAX_NUM_WORDS) {
        int found = 0;
        for (int i = 0; i < numwords; ++i) {
            if (strcasecmp(word, words[i]) == 0) {
                ++frequencies[i];
                found = 1;
                break;
            }
        }
        if (!found) {
            words[numwords] = strdup(word);
            frequencies[numwords++] = 1;
        }
        word = strtok(NULL, " \n\t\r");
    }

    for (int i = 0; i < numwords; ++i) {
        printf("'%s' occurs %d times\n", words[i], frequencies[i]);
        free(words[i]);
    }

    printf("\nThanks for using my word frequency counter!\n");
    return 0;
}
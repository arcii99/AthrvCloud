//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

int main() {
    char text[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS]={0}, word_count = 0, i, j, flag;

    printf("My dearest love, please enter your sweet message: \n");
    while (scanf("%s", text) == 1 && word_count < MAX_WORDS) {
        flag = 0;
        for (i = 0; i < word_count; i++) {
            if (strcmp(text, words[i]) == 0) {
                frequency[i]++;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            strcpy(words[word_count], text);
            frequency[word_count++]++;
        }
    }
    printf("\nMy lovely, here are the word frequency counts: \n");

    // Displaying frequency of all words
    for (i = 0; i < word_count; i++) {
        printf("%-15s%3d\n", words[i], frequency[i]);
    }
    return 0;
}
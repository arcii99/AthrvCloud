//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

int main(void) {
    char text[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS];
    int n, i, j, count;
    
    printf("Enter the text: \n");
    fgets(text[MAX_WORDS], MAX_WORD_LENGTH, stdin);

    n = strlen(text[MAX_WORDS]);
    if (text[MAX_WORDS][n-1] == '\n') text[MAX_WORDS][n-1] = '\0';

    n = 0;
    char* word = strtok(text[MAX_WORDS], " ");
    while (word != NULL) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (strcmp(word, text[i]) == 0) {
                freq[i]++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            strcpy(text[n], word);
            freq[n] = 1;
            n++;
        }
        word = strtok(NULL, " ");
    }

    printf("\nWord frequency in the text: \n");
    for (i = 0; i < n; i++) {
        printf("%s: %d\n", text[i], freq[i]);
    }
    
    return 0;
}
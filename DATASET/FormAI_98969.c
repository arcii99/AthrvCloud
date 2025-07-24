//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000 // Maximum size of input string
#define MAX_WORDS 100 // Maximum number of words in input string

void main() {
    char str[MAX_SIZE];
    char words[MAX_WORDS][MAX_SIZE];
    int freq[MAX_WORDS];    // frequency of each word
    int i, j, count;

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strlen(str) - 1] = '\0';  // remove newline character

    // Splitting input string into words
    count = 0;
    j = 0;
    for (i = 0; i <= strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            words[count][j] = '\0';
            count++;
            j = 0;
        } else {
            words[count][j] = str[i];
            j++;
        }
    }

    // count frequency of each word
    for (i = 0; i < count; i++) {
        freq[i] = 1;
        for (j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[i]++;
                strcpy(words[j], "");
            }
        }
    }

    // print words and their frequency
    printf("\nWord frequency:\n");
    for (i = 0; i < count; i++) {
        if (strcmp(words[i], "") != 0) {
            printf("%s : %d\n", words[i], freq[i]);
        }
    }
}
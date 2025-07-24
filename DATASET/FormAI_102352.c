//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

int main() {
    char words[MAX_WORDS][MAX_LENGTH];
    char word[MAX_LENGTH];
    int word_count = 0;
    int i;

    printf("Enter words (max 1000, max length 50): \n");
    while (scanf("%s", word) == 1) {
        if (word_count >= MAX_WORDS) {
            printf("Maximum words reached.\n");
            break;
        }
        if (strlen(word) > MAX_LENGTH) {
            printf("Word too long.\n");
            continue;
        }
        for (i = 0; i<strlen(word); i++) {
            if (!isalpha(word[i])) {
                printf("Invalid character in word.\n");
                break;
            }
        }
        if (i < strlen(word)) {
            continue;
        }
        strcpy(words[word_count], word);
        word_count++;
    }

    printf("Word list:\n");
    for (i = 0; i<word_count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
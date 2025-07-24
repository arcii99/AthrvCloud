//FormAI DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

int main() {

    char word[MAX_WORD_LENGTH + 1];
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH + 1] = {"apple", "banana", "cherry", "date", "eggplant", "fig", "grape", "honeydew"};
    int i, j, n;

    printf("Enter a word to check spelling: ");
    scanf("%s", word);

    for (i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]);

    n = strlen(word);

    for (i = 0; i < MAX_WORDS; i++) {
        if (strlen(dictionary[i]) == n) {
            for (j = 0; j < n; j++) {
                if (word[j] != dictionary[i][j])
                    break;
            }
            if (j == n) {
                printf("The word %s is spelled correctly.\n", word);
                return 0;
            }
        }
    }
    printf("The word %s is misspelled.\n", word);
    return 0;
}
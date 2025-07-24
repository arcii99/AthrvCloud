//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a word is spelled correctly */
int spell_check(char *word) {
    /* List of known words */
    char *words[] = {"hello", "world", "computer", "science", "programming"};
    int n = sizeof(words) / sizeof(words[0]);

    /* Convert word to lowercase */
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    /* Check if word matches any known word */
    for (int i = 0; i < n; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1; /* Word is spelled correctly */
        }
    }

    return 0; /* Word is misspelled */
}

int main() {
    /* Prompt user for input */
    char input[100];
    printf("Enter a sentence to spell check: ");
    fgets(input, sizeof(input), stdin);

    /* Tokenize input into words */
    char *word = strtok(input, " ,.!?");

    /* Loop through each word and spell check it */
    while (word != NULL) {
        if (spell_check(word)) {
            printf("%s ", word);
        } else {
            printf("(%s) ", word);
        }
        word = strtok(NULL, " ,.!?");
    }

    return 0;
}
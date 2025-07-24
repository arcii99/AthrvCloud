//FormAI DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a word is spelled correctly */
int check_spelling(char *word, char **dictionary, int dict_size) {
    int i;
    for(i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word is correctly spelled
        }
    }
    return 0; // Word is misspelled
}

/* Function to convert a word to lowercase */
void to_lower(char *word) {
    int i;
    for(i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    /* Dictionary of words */
    char *dictionary[] = {"hello", "world", "donald", "knuth", "unique", "code", "example"};

    /* Size of dictionary */
    int dict_size = sizeof(dictionary) / sizeof(dictionary[0]);

    /* Input word */
    char word[20];

    printf("Enter word to check spelling: ");
    scanf("%s", word);

    /* Convert word to lowercase */
    to_lower(word);

    /* Spell check */
    if (check_spelling(word, dictionary, dict_size)) {
        printf("Correctly spelled.\n");
    } else {
        printf("Misspelled.\n");
    }

    return 0;
}
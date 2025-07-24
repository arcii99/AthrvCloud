//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a word is spelled correctly. 
   Returns 0 if spelled correctly, 1 otherwise. */
int check_spelling(char *word) {
    /* List of correct spellings */
    char *correct_spellings[5] = {"apple", "banana", "orange", "grape", "watermelon"};

    /* Check if word is in list of correct spellings */
    for (int i = 0; i < 5; i++) {
        if (strcmp(word, correct_spellings[i]) == 0) {
            return 0;
        }
    }

    return 1;
}

/* Function to check the spelling of a sentence */
void spell_check(char *sentence) {
    char *word;
    /* Split sentence into words */
    word = strtok(sentence, " ");
    while (word != NULL) {
        /* Convert word to lowercase and remove any punctuation */
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
            if (!isalpha(word[i])) {
                memmove(&word[i], &word[i + 1], strlen(word) - i);
                i--;
            }
        }
        /* Check spelling of word */
        if (check_spelling(word)) {
            printf("%s is misspelled.\n", word);
        }
        /* Get next word */
        word = strtok(NULL, " ");
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence to check for spelling errors: ");
    fgets(sentence, sizeof(sentence), stdin);
    /* Remove newline character from input */
    sentence[strcspn(sentence, "\n")] = 0;
    spell_check(sentence);
    return 0;
}
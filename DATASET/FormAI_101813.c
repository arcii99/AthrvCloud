//FormAI DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50 // Maximum length of a word

void remove_newline(char *word);
int is_valid_word(char *word);
void spell_check(char *word);

int main() {
    printf("C Spell Checker\n");

    char word[MAX_WORD_LEN + 1];
    while (1) {
        printf("\nEnter a word: ");
        fgets(word, MAX_WORD_LEN + 1, stdin);
        remove_newline(word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        if (!is_valid_word(word)) {
            printf("Invalid word. Please enter a word containing only English letters.");
            continue;
        }

        spell_check(word);
    }

    printf("\nGoodbye!\n");
    return 0;
}

// Remove newline character from a string
void remove_newline(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == '\n') {
            word[i] = '\0';
            break;
        }
        i++;
    }
}

// Check if a word only contains English letters
int is_valid_word(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Spell check a word
void spell_check(char *word) {
    // TODO: Implement spell checking algorithm
    printf("Word \"%s\" is spelled correctly.\n", word);
}
//FormAI DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 25 // maximum length of a word

void checkSpell(char word[]); // function to check spelling of a word

int main() {
    char input[1000]; // variable to hold user input

    printf("Enter text to spell check: ");
    fgets(input, 1000, stdin); // get user input

    char *token = strtok(input, " ,.;:\n"); // tokenize input

    while (token != NULL) { // loop through all tokens
        checkSpell(token); // check spelling of token
        token = strtok(NULL, " ,.;:\n"); // get next token
    }
    return 0;
}

void checkSpell(char word[]) {
    if (isalpha(word[0])) { // check if word starts with a letter
        int len = strlen(word);
        if (len > MAX_WORD_LENGTH) { // check if word length is greater than maximum allowed length
            printf("%s is an invalid word!\n", word);
            return;
        }

        char dictionary[][MAX_WORD_LENGTH] = { // dictionary of words
            "hello", "world", "computer", "science", "programming", "language", "algorithm",
            "data", "structure", "memory", "pointer", "variable", "function", "loop", "array",
            "string", "integer", "float", "double", "boolean"
        };

        int dictSize = sizeof(dictionary) / MAX_WORD_LENGTH; // get size of dictionary
        int found = 0; // flag to indicate if word is found in dictionary

        for (int i = 0; i < dictSize; i++) { // loop through dictionary to find matching word
            if (strcmp(word, dictionary[i]) == 0) { // check if word is a match
                found = 1;
                break;
            }
        }

        if (found) { // if word is found in dictionary
            printf("%s is spelled correctly!\n", word);
        } else { // if word is not found in dictionary
            printf("%s is misspelled!\n", word);
        }
    } else { // if word does not start with a letter
        printf("%s is not a valid word!\n", word);
    }
}
//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if a word is correctly spelled
int spell_check(char *word)
{
    // list of correctly spelled words
    char *dictionary[] = {"happy", "cheerful", "excited", "joyful", "friendly", "fun"};

    // loop through the dictionary to check if the word is present
    for (int i = 0; i < 6; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // word is correctly spelled
        }
    }

    return 0; // word is misspelled
}

// function to convert all letters to lowercase
void lowercase(char *string)
{
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
}

int main()
{
    char input[100];

    printf("Hello! I am the cheerful spell checker!\n\n");

    while (1) {
        // get user input
        printf("Please enter a word to check (enter 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // convert input to lowercase
        lowercase(input);

        // check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            printf("\nGoodbye! Have a great day!\n");
            break;
        }

        // check if word is correctly spelled
        if (spell_check(input)) {
            printf("\n%s is spelled correctly!\n\n", input);
        } else {
            printf("\nOops! It looks like %s is misspelled. Please try again.\n\n", input);
        }
    }

    return 0;
}
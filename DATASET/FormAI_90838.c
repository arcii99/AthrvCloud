//FormAI DATASET v1.0 Category: Spell checking ; Style: brave
// Welcome to Brave Spell Checker Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is spelled correctly
int spell_checker(char* word) {
    // Dictionary of some commonly used words
    char dictionary[10][20] = {"hello", "world", "computer", "program", "code", 
                            "variable", "function", "pointer", "syntax", "algorithm"};

    // Convert word to lowercase
    char lowercase_word[20];
    int i;
    for(i=0; i<strlen(word); i++) {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[i] = '\0';

    // Check if the word is in the dictionary
    for(i=0; i<10; i++) {
        if(strcmp(lowercase_word, dictionary[i]) == 0) {
            return 1;   // Word is spelled correctly
        }
    }

    return 0;   // Word is misspelled
}

int main() {
    // Welcome message
    printf("Welcome to Brave Spell Checker Program!\n");
    printf("Enter a sentence to spell check or type 'exit' to quit.\n");

    char input[100];    // To store user input

    // Loop to take multiple inputs
    while(1) {
        // Take user input
        printf("\nEnter a sentence: ");
        fflush(stdin);  // Flush input buffer
        fgets(input, 100, stdin);

        // Check if user wants to exit
        if(strcmp(input, "exit\n") == 0) {
            printf("\nGoodbye!\n");
            break;
        }

        // Check each word in the sentence
        char* word = strtok(input, " .,!?\n");
        int num_mistakes = 0;   // To count number of mistakes
        printf("Misspelled words: ");
        while(word != NULL) {
            if(!spell_checker(word)) {
                // Print misspelled word and increase mistake counter
                printf("%s ", word);
                num_mistakes++;
            }
            word = strtok(NULL, " .,!?\n");
        }

        // Print spell check summary
        if(num_mistakes == 0) {
            printf("\nNo spelling mistakes found!");
        } else if(num_mistakes == 1) {
            printf("\n1 spelling mistake found.");
        } else {
            printf("\n%d spelling mistakes found.", num_mistakes);
        }
    }

    return 0;   // End program
}
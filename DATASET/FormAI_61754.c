//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 100

// Define the alien language dictionary
const char *ALIEN_WORDS[] = {"zog", "grak", "thok", "plax", "smik", "quee", "blon", "snix", "frax", "grom"};

const int NUM_ALIEN_WORDS = 10;

// Define the human language dictionary
const char *HUMAN_TRANSLATIONS[] = {"hello", "goodbye", "yes", "no", "please", "thank you", "sorry", "friend", "enemy", "help"};

const int NUM_HUMAN_TRANSLATIONS = 10;

// Declare the function that will translate the alien language to human language
void translate_alien_to_human(char *alien_word);

int main() {
    printf("Welcome to the Alien Language Translator!\n\n");
    printf("Please enter your name: ");
    
    char name[MAX_STRING_SIZE];
    fgets(name, MAX_STRING_SIZE, stdin);
    strtok(name, "\n");  // Remove the newline character from the input
    
    printf("\nHello, %s! Let's get started.\n", name);
    
    while (1) {
        printf("\nEnter an alien word you want to translate or enter 'quit' to exit: ");
        
        char alien_word[MAX_STRING_SIZE];
        fgets(alien_word, MAX_STRING_SIZE, stdin);
        strtok(alien_word, "\n");  // Remove the newline character from the input
        
        // Check if the user entered 'quit' to exit the program
        if (strcmp(alien_word, "quit") == 0) {
            printf("\nThank you for using the Alien Language Translator, %s!\n", name);
            break;
        }
        
        // Translate the alien word to human language
        translate_alien_to_human(alien_word);
    }
    
    return 0;
}

void translate_alien_to_human(char *alien_word) {
    // Search through the alien language dictionary to find the corresponding index of the alien word input
    int index = -1;
    for (int i = 0; i < NUM_ALIEN_WORDS; i++) {
        if (strcmp(ALIEN_WORDS[i], alien_word) == 0) {
            index = i;
            break;
        }
    }
    
    // Check if the alien word was found in the dictionary
    if (index != -1) {
        printf("\nThe alien word '%s' translates to '%s' in human language.\n", alien_word, HUMAN_TRANSLATIONS[index]);
    } else {
        printf("\nSorry, the alien word '%s' was not found in the dictionary.\n", alien_word);
    }
}
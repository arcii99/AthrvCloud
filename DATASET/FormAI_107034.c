//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

// Define translations for each English word
const char* translations[] = {
    "meow",     // cat
    "purr",     // happy
    "hiss",     // angry
    "snore",    // sleep
    "stretch",  // wake up
    // feel free to add more translations here!
};

// Translate a single word to C Cat Language
void translate_word(char* word) {
    // Convert the word to lowercase to match the translations array
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    
    // Find the translation for the word, or keep the original word if not found
    const int num_translations = sizeof(translations) / sizeof(translations[0]);
    for (int i = 0; i < num_translations; i++) {
        if (strcmp(word, translations[i]) == 0) {
            strcpy(word, translations[i]);
            return;
        }
    }
}

int main() {
    // Print a welcome message
    printf("Welcome to the C Cat Language Translator!\n");
    
    // Loop until the user enters "quit"
    while (1) {
        // Prompt the user for input
        printf("Please enter a phrase in English (or quit to exit): ");
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // remove newline character
        
        // Check if the user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        // Split the input into words using strtok
        char* word = strtok(input, " ");
        while (word != NULL) {
            // Translate the word and print it
            translate_word(word);
            printf("%s ", word);
            word = strtok(NULL, " ");
        }
        printf("\n");
    }
    
    // Print a goodbye message
    printf("Thanks for using the C Cat Language Translator!\n");
    return 0;
}
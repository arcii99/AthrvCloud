//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a dictionary to map C Cat words to English words
char* catspeak[] = {"meow", "purr", "hiss", "scratch", "nap", 
                    "play", "hunt", "eat", "drink", "clean"};

char* english[] = {"hello", "happy", "angry", "annoyed", "sleep", 
                    "fun", "chase", "food", "water", "groom"};

int main() {
    char input[100]; // Prepare a buffer to accept user input
    printf("Welcome to the C Cat Language Translator!\n");
    while(1) { // Keep looping until the program is quit
        printf("Enter a sentence in C Cat language or enter 'quit' to exit.\n");
        fgets(input, sizeof(input), stdin); // Get input from the user
        if (strncmp(input, "quit", 4) == 0) { // Check for the quit command
            printf("Quitting the program.\n");
            break; // Exit the loop and end the program
        }
        // Begin translating the C Cat sentence into English
        char* token = strtok(input, " "); // split the sentence into words
        int translated = 0; // Flag indicating if any translation was made
        while (token != NULL) {
            for (int i = 0; i < 10; i++) { // Compare each C Cat word to the dictionary
                if (strncmp(token, catspeak[i], strlen(catspeak[i])) == 0) {
                    printf("%s ", english[i]); // Print the corresponding English word
                    translated = 1; // Set the flag to true
                    break; // Exit the inner loop since the word was found
                }
            }
            // If no translation was made, print the original word
            if (!translated) {
                printf("%s ", token);
            }
            token = strtok(NULL, " "); // Get the next word in the sentence
            translated = 0; // Reset the flag for the next word
        }
        printf("\n"); // Add a new line after the translated sentence
    }
    return 0; // End the program
}
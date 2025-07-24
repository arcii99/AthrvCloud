//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien Language dictionary
char* alienLanguage[] = {"Zorg", "Blarg", "Klorg", "Gornt", "Flurb", "Nerth"};

// Define the English Language dictionary
char* englishLanguage[] = {"Hello", "World", "Goodbye", "Thank you", "Yes", "No"};

// Define the translation function
char* translate(char* input) {
    for(int i = 0; i < 6; i++) {
        if(strcmp(input, alienLanguage[i]) == 0) {
            return englishLanguage[i];
        }
    }
    return "Invalid Input";
}

int main() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a word in Alien Language: ");
    
    char input[20];
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = 0;
    // Remove the trailing newline character
    
    char* translation = translate(input);
    printf("The translation is: %s\n", translation);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

// Function to translate a single alien word to English
char* translateAlienWord(char* alienWord) {
    // Perform necessary translation here
    // For example, replace characters with their English equivalents
    if (strcmp(alienWord, "grax") == 0) {
        return "hello";
    } else if (strcmp(alienWord, "snorp") == 0) {
        return "goodbye";
    } else if (strcmp(alienWord, "flibbertigibbet") == 0) {
        return "random";
    } else {
        return "unknown";
    }
}

// Function to translate an entire alien phrase to English
void translateAlienPhrase(char* alienPhrase) {
    // Tokenize the alien phrase into individual words
    char* token = strtok(alienPhrase, " ");

    // Translate each alien word and print the result
    while (token != NULL) {
        // Translate the current alien word to English
        char* englishWord = translateAlienWord(token);

        // Print the translated word
        printf("%s ", englishWord);

        // Move to the next token
        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main(void) {
    printf("Enter an alien phrase to translate: ");

    // Read user input from the console
    char input[100];
    fgets(input, 100, stdin);

    // Remove trailing newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Translate the alien phrase and print the result
    translateAlienPhrase(input);

    return 0;
}
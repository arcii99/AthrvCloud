//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

char* alienTranslator(char* input) {

    // Define a dictionary of alien language words and their translations
    char* dictionary[7][2] = {
        {"kazam", "hello"},
        {"veelox", "goodbye"},
        {"sonto", "peace"},
        {"youtine", "friend"},
        {"morsulu", "love"},
        {"taloba", "thank you"},
        {"zintar", "home"}
    };

    // Tokenize the input string
    char delim[] = " ";
    char* token = strtok(input, delim);

    // Translate each word in the input string
    char* translated = "";
    while (token != NULL) {
        // Search for the corresponding translation in the dictionary
        for (int i = 0; i < 7; i++) {
            if (strcmp(token, dictionary[i][0]) == 0) {
                // Append the translation to the output string
                translated = strcat(translated, dictionary[i][1]);
                translated = strcat(translated, " ");
                break;
            }
        }
        // Move on to the next word in the input string
        token = strtok(NULL, delim);
    }

    // Return the translated string
    return translated;
}

int main() {

    // Prompt the user for input
    char input[100];
    printf("Enter a phrase in alien language: ");
    fgets(input, 100, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    // Translate the input string
    char* translated = alienTranslator(input);

    // Print the translated string
    printf("%s\n", translated);

    return 0;
}
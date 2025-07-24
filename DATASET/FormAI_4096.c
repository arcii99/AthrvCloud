//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    // Initializing the alien language dictionary
    char* alienWords[] = { "fqefh", "lfjds", "brglt", "khopr", "znvyc", "wdlcq" };
    char* englishWords[] = { "hello", "world", "earth", "planet", "alien", "universe" };
    int numWords = 6;

    // Prompting user for an alien word
    char input[20];
    printf("Enter an alien word: ");
    scanf("%s", input);

    // Searching for the inputted alien word in the dictionary
    int i;
    int matchFound = 0;
    for (i = 0; i < numWords; i++) {
        if (strcmp(alienWords[i], input) == 0) {
            printf("Translation: %s\n", englishWords[i]);
            matchFound = 1;
            break;
        }
    }

    // Displaying an error message if no match is found
    if (matchFound == 0) {
        printf("Error: Alien word not found.\n");
    }

    return 0;
}
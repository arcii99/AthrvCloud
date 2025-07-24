//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>

int main() {

    // Define an array of C cat words and their English translations
    char cwords[10][20] = {
        {"purr"},
        {"meow"},
        {"mlem"},
        {"hiss"},
        {"scratch"},
        {"lap"},
        {"play"},
        {"kitten"},
        {"nibble"},
        {"catnip"}
    };
   
    char ewords[10][20] = {
        {"Hello"},
        {"Feed me"},
        {"I'm happy"},
        {"Stay away"},
        {"I need a scratch"},
        {"Let me sit on your lap"},
        {"Let's play"},
        {"I'm young"},
        {"Let me bite"},
        {"I want some catnip"}
    };

    char input[20];
    printf("Enter a C cat word to translate to English:\n");
    scanf("%s", input);

    // Iterate through the C cat words and their translations and compare if the input is a C cat word
    for (int i = 0; i < 10; i++) {
        if (strcmp(input, cwords[i]) == 0) {
            printf("English Translation: %s\n", ewords[i]);
            return 0;
        }
    }

    // If the input is not a C cat word, print an error message
    printf("Error: %s is not a valid C cat word.\n", input);

    return 0;
}
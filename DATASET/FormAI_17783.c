//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter a sentence in cat language: ");
    scanf("%[^\n]", input);
    getchar(); // Consume the extra new line character

    char translated[1000];
    int index = 0;

    // Iterate through every character in the input sentence
    for (int i = 0; i < strlen(input); i++) {
        // If the current character is "m", replace it with "meow"
        if (input[i] == 'm') {
            strcat(translated, "meow");
            index += 4;
        }
        // If the current character is "i", replace it with "in"
        else if (input[i] == 'i') {
            strcat(translated, "in");
            index += 2;
        }
        // If the current character is "y", replace it with "you"
        else if (input[i] == 'y') {
            strcat(translated, "you");
            index += 3;
        }
        // Otherwise, just copy the character as it is
        else {
            translated[index] = input[i];
            index++;
        }
    }
    translated[index] = '\0'; // Add null terminator to the end of the string

    printf("Your sentence translated to English: %s\n", translated);

    return 0;
}
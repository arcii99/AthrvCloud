//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate the alien language
void translate_language(char* input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        // If the input character is uppercase
        if (input[i] >= 'A' && input[i] <= 'Z') {
            // Subtract 34 from the ASCII value to get the translated character
            input[i] = (char)((int)input[i] - 34);
        }
        // If the input character is lowercase
        else if (input[i] >= 'a' && input[i] <= 'z') {
            // Subtract 62 from the ASCII value to get the translated character
            input[i] = (char)((int)input[i] - 62);
        }
    }

    // Print the translated message
    printf("Translated message: %s", input);
}

int main() {
    char input[50];

    // Get the user input
    printf("Enter the message to be translated: ");
    scanf("%[^\n]", input);

    // Translate the message
    translate_language(input);

    return 0;
}
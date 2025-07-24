//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to Morse code
char* charToMorse(char c) {
    // Array to hold the Morse code for each character
    char* morseCodes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    // If the character is a space, return a space character
    if (c == ' ') {
        return " ";
    }

    // If the character is a uppercase letter, convert to lowercase
    if (c >= 'A' && c <= 'Z') {
        c += 32;
    }

    // If the character is not a letter or a space, return NULL
    if (!(c >= 'a' && c <= 'z')) {
        return NULL;
    }

    // Return the Morse code for the character
    return morseCodes[c - 'a'];
}

int main() {
    // Prompt the user for a message to convert
    printf("Enter a message to convert to Morse code: ");

    // Read in the message from the user
    char message[100];
    fgets(message, 100, stdin);

    // Loop through the message and convert each character to Morse code
    for (int i = 0; i < strlen(message); i++) {
        // Convert the current character to Morse code
        char* morseCode = charToMorse(message[i]);

        // If the character is not a letter or a space, print an error message
        if (morseCode == NULL) {
            fprintf(stderr, "Error: Character '%c' cannot be converted to Morse code.\n", message[i]);
        } else {
            // Print the Morse code for the current character
            printf("%s ", morseCode);
        }
    }

    // Print a newline character at the end of the output
    printf("\n");

    return 0;
}
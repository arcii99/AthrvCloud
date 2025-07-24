//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// Function to translate a single alien character to English
char translate_char(char c) {
    switch(c) {
        case 'a': return 'e';
        case 'b': return 't';
        case 'c': return 'h';
        case 'd': return 'o';
        // Add more cases for additional characters
        default: return c; // If character is not known, leave it as is
    }
}

int main() {
    // Read in message from the user
    char message[1024];
    printf("Enter message to translate: ");
    fgets(message, 1024, stdin);
    message[strlen(message)-1] = '\0'; // Remove trailing newline character

    // Translate message
    char translated[1024];
    for(int i=0; i<strlen(message); i++) {
        translated[i] = translate_char(message[i]);
    }
    translated[strlen(message)] = '\0'; // Add null terminator to end of string

    // Print translated message
    printf("Translated message: %s\n", translated);

    return 0;
}
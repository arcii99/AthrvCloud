//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 100 // Maximum number of characters allowed in the message
#define ALIEN_CHARS "xzobkjqpu" // The unique set of alien characters

int main() {

    // Initialize variables
    char message[MAX_CHARS];
    char translated[MAX_CHARS];
    int i, j, len;

    // Get message from user
    printf("Enter message in alien language: ");
    fgets(message, MAX_CHARS, stdin);
    len = strlen(message);

    // Translate message
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(ALIEN_CHARS); j++) {
            if (message[i] == ALIEN_CHARS[j]) {
                translated[i] = (char)('a' + j);
            }
        }
        if (!translated[i]) {
            translated[i] = message[i];
        }
    }

    // Display translated message
    printf("Translated message: %s", translated);

    return 0;
}
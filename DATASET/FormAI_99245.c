//FormAI DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
    // Input string
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    // Post-apocalyptic style string manipulation
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == 'e') {
            message[i] = '3'; // Replace 'e' with '3'
        } else if (message[i] == 'o') {
            message[i] = '0'; // Replace 'o' with '0'
        } else if (message[i] == 's') {
            message[i] = 'z'; // Replace 's' with 'z'
        } else if (message[i] == 't') {
            message[i] = '7'; // Replace 't' with '7'
        }
    }

    printf("Your post-apocalyptic message: %s\n", message);
    return 0;
}
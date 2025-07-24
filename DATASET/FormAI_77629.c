//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the shift value for the Caesar Cipher
#define SHIFT 3

// Function to encrypt a given message using the Caesar Cipher
char* encrypt(char* message) {
    int i;
    char* result = malloc(strlen(message) + 1);
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            int c = message[i] + SHIFT;
            if (isupper(message[i]) && c > 'Z') {
                c -= 26;
            } else if (islower(message[i]) && c > 'z') {
                c -= 26;
            }
            result[i] = c;
        } else {
            result[i] = message[i];
        }
    }
    result[i] = '\0';
    return result;
}

// Main function to run the program
int main() {
    // Get a message to encrypt from the user
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    // Encrypt the message using the Caesar Cipher
    char* encrypted_message = encrypt(message);

    // Print the encrypted message
    printf("The encrypted message is: %s\n", encrypted_message);

    // Free the memory used by the encrypted message
    free(encrypted_message);

    return 0;
}
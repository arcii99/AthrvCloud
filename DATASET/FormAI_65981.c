//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
char* encryptMessage(char* message) {
    int len = strlen(message);
    char* encryptedMessage = (char*) malloc((len + 1) * sizeof(char));
    encryptedMessage[len] = '\0';

    for(int i = 0; i < len; i++) {
        encryptedMessage[i] = message[i] + 2; // Encrypt each character by shifting it two positions in the ASCII table
    }

    return encryptedMessage;
}

int main() {
    printf("Welcome to the encryption program inspired by the cases of Sherlock Holmes!\n");

    // Get the message to encrypt from the user
    char message[100];
    printf("Please enter the message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove any newline characters from the message
    int pos = 0;
    while(message[pos] != '\n' && pos < 100) {
        pos++;
    }
    message[pos] = '\0';

    // Encrypt the message using the unique encryption algorithm
    char* encryptedMessage = encryptMessage(message);

    printf("The encrypted message is: %s\n", encryptedMessage);

    free(encryptedMessage); // Free the memory allocated for the encrypted message

    return 0;
}
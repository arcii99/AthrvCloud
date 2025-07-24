//FormAI DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 50

// Function to encrypt the given string using Caesar cipher
void encrypt(char* message, int key) {
    int i;

    // Iterate through each character in the string
    for (i = 0; message[i] != '\0'; ++i) {

        // check if character is lowercase alphabet
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        
        // check if character is uppercase alphabet
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
    }
}

int main() {
    char message[MAX_STRING_LENGTH];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Remove newline character from message if present
    if ((strlen(message) > 0) && (message[strlen (message) - 1] == '\n'))
        message[strlen (message) - 1] = '\0';

    // encrypt the message
    encrypt(message, key);

    // print the encrypted message
    printf("\nEncrypted message: %s\n", message);

    return 0;
}
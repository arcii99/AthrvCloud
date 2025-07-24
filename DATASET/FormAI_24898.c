//FormAI DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our unique encryption function
void encrypt(char* message, int key) {
    int length = strlen(message);

    // Let's iterate over every character in the message
    for (int i = 0; i < length; i++) {
        // If it's uppercase, we shift it up the alphabet (wrapping around if it goes off the end)
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        // If it's lowercase, we do the same thing, but with lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        // For anything else (like spaces or punctuation), we leave it unchanged
    }
}

int main() {
    int key = 42;

    // Let's get a message to encrypt from the user
    char message[100];
    printf("Please enter the message you want to encrypt (max 100 characters):\n");
    fgets(message, 100, stdin);
    // Since we're using fgets, we need to strip off the newline character at the end
    message[strcspn(message, "\n")] = '\0';

    // Now let's encrypt it and print out the result
    encrypt(message, key);
    printf("\nYour encrypted message is: %s\n", message);

    return 0;
}
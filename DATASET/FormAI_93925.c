//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the input string using Caesar Cipher
void encrypt(char *str, int key) {
    if (*str == '\0') // base case
        return;
    else {
        // encrypt current character if it is an alphabet
        if (*str >= 'a' && *str <= 'z') {
            *str = (*str + key - 'a') % 26 + 'a';
        } else if (*str >= 'A' && *str <= 'Z') {
            *str = (*str + key - 'A') % 26 + 'A';
        }

        // Recursively call encrypt on remaining string
        encrypt(str + 1, key);
    }
}

int main() {
    char message[100];
    int key;

    // Read input message and key from user
    printf("Enter message to encrypt (must be only alphabets): ");
    scanf("%s", message);
    printf("Enter key (must be an integer): ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}
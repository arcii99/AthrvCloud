//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message using Caesar Cipher
char *encrypt(char *msg, int key) {
    char *encrypted_msg = (char *) malloc(strlen(msg) + 1);  // Allocated memory for encrypted message
    int i;

    for (i = 0; msg[i] != '\0'; i++) {
        if (isalpha(msg[i])) {  // Check if the character is an alphabet
            char base = isupper(msg[i]) ? 'A' : 'a';  // Set the base to 'A' or 'a' depending on uppercase or lowercase character
            encrypted_msg[i] = (msg[i] - base + key) % 26 + base;  // Encrypt the character
        } else {
            encrypted_msg[i] = msg[i];  // Copy the character as is
        }
    }

    encrypted_msg[i] = '\0';  // Null terminate the encrypted message
    return encrypted_msg;
}

int main() {
    char msg[100];  // Message to encrypt
    int key;  // Encryption key

    printf("Enter the message to encrypt: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';  // Remove newline character from the end of the string

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    char *encrypted_msg = encrypt(msg, key);

    printf("Encrypted message: %s\n", encrypted_msg);

    free(encrypted_msg);  // Free the allocated memory

    return 0;
}
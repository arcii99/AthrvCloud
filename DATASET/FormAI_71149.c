//FormAI DATASET v1.0 Category: Modern Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define key for encryption and decryption */
const int key = 10;

/* Function to encrypt a character */
char encryptChar(char ch) {
    return (ch - 'a' + key) % 26 + 'a';
}

/* Function to encrypt a string */
void encryptString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = encryptChar(str[i]);
    }
}

/* Function to decrypt a character */
char decryptChar(char ch) {
    return (ch - 'a' - key + 26) % 26 + 'a';
}

/* Function to decrypt a string */
void decryptString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = decryptChar(str[i]);
    }
}

/* Main function */
int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    /* Remove newline character from message */
    message[strcspn(message, "\n")] = 0;

    /* Encrypt message */
    encryptString(message);
    printf("Encrypted message: %s\n", message);

    /* Decrypt message */
    decryptString(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}
//FormAI DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 3 // Define a key for the encryption algorithm

void encryption(char *message) {
    int i = 0;
    while(message[i] != '\0') {
        message[i] += ENCRYPT_KEY; // Add the key to each character
        i++;
    }
}

void decryption(char *message) {
    int i = 0;
    while(message[i] != '\0') {
        message[i] -= ENCRYPT_KEY; // Subtract the key from each character
        i++;
    }
}

int main(void) {
    char message[100];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    encryption(message);
    printf("Encrypted message is: %s", message);
    decryption(message);
    printf("Decrypted message is: %s", message);
    return 0;
}
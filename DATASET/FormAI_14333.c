//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to encrypt the message
void encrypt(char *message, char *key) {
    int lenM = strlen(message);
    int lenK = strlen(key);
    int i, j = 0;

    for(i = 0; i < lenM; i++) {
        message[i] = message[i] ^ key[j];
        j++;
        if(j >= lenK) {
            j = 0;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, char *key) {
    encrypt(message, key);
}

// Main function
int main() {
    char message[100];
    char key[100];

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}
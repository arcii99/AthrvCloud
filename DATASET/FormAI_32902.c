//FormAI DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[]) {
    int key = 3;
    int length = strlen(message);

    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
    }
}

void decrypt(char message[]) {
    int key = 3;
    int length = strlen(message);

    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[1000];

    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    printf("\nOriginal message: %s", message);

    encrypt(message);
    printf("Encrypted message: %s", message);

    decrypt(message);
    printf("Decrypted message: %s", message);

    return 0;
}
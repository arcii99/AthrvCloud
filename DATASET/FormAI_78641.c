//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        message[i] += key;
    }
}

void decrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        message[i] -= key;
    }
}

int main() {
    char message[50];
    int key, choice;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    printf("\n1. Encrypt\n2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(message, key);
            printf("\nEncrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("\nDecrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
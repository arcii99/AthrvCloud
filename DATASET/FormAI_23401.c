//FormAI DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted = (char*) malloc(sizeof(char) * (length + 1));
    int i, j;
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (char) (((message[i] - 'a' + key) % 26) + 'a');
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (char) (((message[i] - 'A' + key) % 26) + 'A');
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';
    return encrypted;
}

// Function to perform decryption
char* decrypt(char* message, int key) {
    int length = strlen(message);
    char* decrypted = (char*) malloc(sizeof(char) * (length + 1));
    int i, j;
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            decrypted[i] = (char) (((message[i] - 'a' - key + 26) % 26) + 'a');
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            decrypted[i] = (char) (((message[i] - 'A' - key + 26) % 26) + 'A');
        } else {
            decrypted[i] = message[i];
        }
    }
    decrypted[i] = '\0';
    return decrypted;
}

int main() {
    char message[1000];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    return 0;
}
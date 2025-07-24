//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include<stdio.h>

// Custom encryption function
void encrypt(char* str, int key) {
    for(int i=0; str[i] != '\0'; ++i) {
        str[i] += key;
    }
}

// Custom decryption function
void decrypt(char* str, int key) {
    for(int i=0; str[i] != '\0'; ++i) {
        str[i] -= key;
    }
}

int main() {
    char message[100];
    int key;

    // Prompt user for message to encrypt
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // Prompt user for encryption key
    printf("\nEnter an encryption key (1-50): ");
    scanf("%d", &key);

    // Encrypt message using custom encryption function
    encrypt(message, key);
    printf("\nEncrypted message: %s", message);

    // Decrypt message using custom decryption function
    decrypt(message, key);
    printf("\nDecrypted message: %s\n", message);

    return 0;
}
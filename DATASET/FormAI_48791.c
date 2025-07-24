//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
char* encrypt(char* data, int key) {
    char* encryptedData = (char*) malloc(strlen(data) * sizeof(char));
    int i;
    for(i=0; i<strlen(data); i++) {
        encryptedData[i] = data[i] + key; // adding key to each character of data string
    }
    encryptedData[i] = '\0';
    return encryptedData;
}

// Decryption function
char* decrypt(char* data, int key) {
    char* decryptedData = (char*) malloc(strlen(data) * sizeof(char));
    int i;
    for(i=0; i<strlen(data); i++) {
        decryptedData[i] = data[i] - key; // subtracting key from each character of data string
    }
    decryptedData[i] = '\0';
    return decryptedData;
}

int main() {
    char data[100];
    int key;

    // User input
    printf("Enter data to encrypt: ");
    fgets(data, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypting user input
    char* encryptedData = encrypt(data, key);
    printf("\nEncrypted data: %s\n", encryptedData);

    // Decrypting previously encrypted user input
    char* decryptedData = decrypt(encryptedData, key);
    printf("\nDecrypted data: %s\n", decryptedData);

    free(encryptedData); // freeing memory
    free(decryptedData);
    return 0;
}
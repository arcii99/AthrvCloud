//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey" // Encryption key

void encrypt(char *plainText, char *cipherText);
void decrypt(char *cipherText, char *plainText);

int main() {
    char *message = "Hello World!"; // Plaintext message
    char cipherText[strlen(message)]; // Encrypted message
    char decryptedText[strlen(message)]; // Decrypted message
    
    encrypt(message, cipherText); // Encrypt the message
    printf("Encrypted Text: %s\n", cipherText);
    
    decrypt(cipherText, decryptedText); // Decrypt the message
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}

// Function to encrypt the plain text using Caesar Cipher algorithm
void encrypt(char *plainText, char *cipherText) {
    int keyLength = strlen(KEY);
    int plainTextLength = strlen(plainText);
    
    for(int i=0; i<plainTextLength; i++) {
        cipherText[i] = ((plainText[i] + KEY[i%keyLength]) % 256);
    }
}

// Function to decrypt the cipher text using Caesar Cipher algorithm
void decrypt(char *cipherText, char *plainText) {
    int keyLength = strlen(KEY);
    int cipherTextLength = strlen(cipherText);
    
    for(int i=0; i<cipherTextLength; i++) {
        plainText[i] = ((cipherText[i] - KEY[i%keyLength] + 256) % 256);
    }
}
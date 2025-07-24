//FormAI DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum string length for encryption.
#define MAX_STRING_LENGTH 1000

// Define encryption key.
#define ENCRYPTION_KEY 31

// Define encryption function.
void encryption(char *inputString, char *encryptedString, int key){
    int i;
    for(i = 0; i < strlen(inputString); i++){
        encryptedString[i] = inputString[i] + key;
    }
    encryptedString[i] = '\0';
}

// Define decryption function.
void decryption(char *encryptedString, char *decryptedString, int key){
    int i;
    for(i = 0; i < strlen(encryptedString); i++){
        decryptedString[i] = encryptedString[i] - key;
    }
    decryptedString[i] = '\0';
}

// Main function.
int main(){
    // Declare variables for input, encrypted, and decrypted strings.
    char inputString[MAX_STRING_LENGTH], encryptedString[MAX_STRING_LENGTH], decryptedString[MAX_STRING_LENGTH];

    // Ask user for input and store it in the input string variable.
    printf("Please enter a string to encrypt: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);

    // Remove newline character from input string.
    inputString[strcspn(inputString, "\n")] = 0;

    // Encrypt the input string.
    encryption(inputString, encryptedString, ENCRYPTION_KEY);

    // Print encrypted string.
    printf("Encrypted string: %s\n", encryptedString);

    // Decrypt the encrypted string.
    decryption(encryptedString, decryptedString, ENCRYPTION_KEY);

    // Print decrypted string.
    printf("Decrypted string: %s\n", decryptedString);

    return 0;
}
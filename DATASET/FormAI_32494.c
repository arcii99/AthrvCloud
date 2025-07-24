//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given string
char* encrypt(char* message, int key) {
    int i;
    char* ciphertext = (char*) malloc(strlen(message) + 1);
    
    // Loop through each character in the message
    for (i = 0; i < strlen(message); i++) {
        char c = message[i];
        
        // If the character is a letter, encrypt it using the key
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + key) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + key) % 26 + 'A';
        }
        
        // Add the encrypted character to the ciphertext
        ciphertext[i] = c;
    }
    
    // Add the null terminator to the ciphertext
    ciphertext[strlen(message)] = '\0';
    
    return ciphertext;
}

int main() {
    char message[] = "This is a secret message.";
    int key = 13;
    char* ciphertext = encrypt(message, key);
    
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", ciphertext);
    
    free(ciphertext);
    return 0;
}
//FormAI DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to encrypt the string
void encrypt(char* string) {
    int i;
    int n = strlen(string);
    
    // Loop through each character in the string
    for (i = 0; i < n; i++) {
        // XOR the character with 5 and store the result in the same variable
        string[i] = string[i] ^ 5;
    }
}

// Function to decrypt the string
void decrypt(char* string) {
    // Call the encrypt function again to decrypt the string
    encrypt(string);
}

int main() {
    char string[MAX_STRING_LENGTH];
    
    // Ask the user for input
    printf("Enter a string: ");
    fgets(string, MAX_STRING_LENGTH, stdin); // Use fgets instead of scanf to prevent buffer overflow
    
    // Encrypt the string
    encrypt(string);
    
    // Print the encrypted string
    printf("Encrypted string: %s", string);
    
    // Decrypt the string
    decrypt(string);
    
    // Print the decrypted string
    printf("Decrypted string: %s", string);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key as a global constant
#define ENCRYPTION_KEY 10

// Function to encrypt a string
char* encrypt(char* string) {
    // Get the length of the string
    int length = strlen(string);
    
    // Allocate memory to store the encrypted string
    char* encrypted_string = (char*)malloc(length * sizeof(char));
    
    // Iterate over the string and replace each character with the encrypted value
    for (int i = 0; i < length; i++) {
        encrypted_string[i] = string[i] + ENCRYPTION_KEY;
    }
    
    // Append a null character to the end of the string
    encrypted_string[length] = '\0';
    
    // Return the encrypted string
    return encrypted_string;
}

int main() {
    // Get a string from the user
    char string[100];
    printf("Enter a string to encrypt: ");
    scanf("%s", string);
    
    // Encrypt the string
    char* encrypted_string = encrypt(string);
    
    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted_string);
    
    // Free the memory allocated for the encrypted string
    free(encrypted_string);
    
    return 0;
}
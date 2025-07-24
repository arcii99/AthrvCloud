//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a given message using a Caesar cipher
char* encrypt(char* message, int key) {
    char* result = (char*) malloc(sizeof(char) * strlen(message));
    
    // Iterate through every character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Shift the character by the given key
        char newChar = message[i] + key;
        
        // If the new character is not in the alphabet, wrap around
        if ((message[i] >= 'a' && message[i] <= 'z' && newChar > 'z') || 
            (message[i] >= 'A' && message[i] <= 'Z' && newChar > 'Z'))
            newChar -= 26;
        
        // Add the encrypted character to the result string
        result[i] = newChar;
    }
    
    return result;
}

int main(void) {
    char message[] = "Hello, World!";
    int key = 5;
    
    // Encrypt the message using a Caesar cipher
    char* encrypted = encrypt(message, key);
    
    // Print the encrypted message
    printf("Encrypted Message: %s\n", encrypted);
    
    // Free the allocated memory
    free(encrypted);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define SHIFT_AMOUNT 3 // Encryption key

char* encrypt(char* message) {
    int i = 0;
    char* result = (char*) malloc(MAX_STRING_LENGTH * sizeof(char)); // Allocate memory for result string
    
    while(message[i] != '\0') {
        if(isalpha(message[i])) { // If character is a letter
            if(isupper(message[i])) { // If character is uppercase
                result[i] = (((message[i] - 'A') + SHIFT_AMOUNT) % 26) + 'A';
            }
            else { // Character is lowercase
                result[i] = (((message[i] - 'a') + SHIFT_AMOUNT) % 26) + 'a';
            }
        }
        else { // Character is not a letter, copy over unchanged
            result[i] = message[i];
        }
        i++;
    }
    result[i] = '\0'; // Add terminating null character
    
    return result;
}

int main() {
    char message[MAX_STRING_LENGTH];
    char* encrypted_message;
    
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin); // Read message input from user
    
    encrypted_message = encrypt(message); // Encrypt message
    
    printf("Encrypted message: %s", encrypted_message); // Print encrypted message
    
    free(encrypted_message); // Free memory
    
    return 0;
}
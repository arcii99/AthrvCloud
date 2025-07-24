//FormAI DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Input message to be encrypted
    char message[100];
    printf("Enter message to be encrypted:\n");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character
    
    // Generate a random encryption key
    int key[10];
    for (int i = 0; i < 10; i++) {
        key[i] = rand() % 26; // Random number between 0 and 25
    }
    
    // Encrypt message using the key
    char encrypted[100];
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            // Convert lowercase letter to corresponding letter in key
            encrypted[i] = 'a' + key[message[i] - 'a'];
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            // Convert uppercase letter to corresponding letter in key
            encrypted[i] = 'A' + key[message[i] - 'A'];
        } else {
            // Copy other characters as is
            encrypted[i] = message[i];
        }
    }
    encrypted[strlen(message)] = '\0'; // Add null terminator
    
    // Display encrypted message and encryption key
    printf("\nEncrypted message:\n%s\n", encrypted);
    printf("Encryption key:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", key[i]);
    }
    
    return 0;
}
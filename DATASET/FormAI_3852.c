//FormAI DATASET v1.0 Category: modern Encryption ; Style: active
#include <stdio.h>
#include <string.h>

// Function prototype
void encrypt(char *plaintext, char *key);

int main(void) {
    // Declare variables
    char plaintext[50];
    char key[50];
    
    // Get user input for plaintext and key
    printf("Enter your message: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter your encryption key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline character from user input
    plaintext[strcspn(plaintext, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    // Call encrypt function
    printf("\nEncrypting message...\n");
    encrypt(plaintext, key);

    return 0;
}

void encrypt(char *plaintext, char *key) {
    // Declare variables
    int plaintextLength = strlen(plaintext);
    int keyLength = strlen(key);
    int i, j;
    char encrypted[50];
    
    // Encrypt plaintext with key
    for (i = 0, j = 0; i < plaintextLength; i++, j++) {
        if (j >= keyLength) {
            j = 0;
        }
        encrypted[i] = (plaintext[i] + key[j]) % 26 + 'A';
    }
    
    // Print encrypted message
    printf("\nEncrypted message: %s\n", encrypted);
}
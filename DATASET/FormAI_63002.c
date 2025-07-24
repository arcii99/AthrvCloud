//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key and the cipher algorithm
#define KEY 10
#define CIPHER_ALGO(x) (x ^ KEY)

int main() {
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];
    
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    
    // Encryption process
    for(int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = CIPHER_ALGO(message[i]);
    }
    
    printf("\nEncrypted message: %s\n", encrypted_message);
    
    // Decryption process
    for(int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = CIPHER_ALGO(encrypted_message[i]);
    }
    
    printf("\nDecrypted message: %s\n", decrypted_message);
    
    return 0;
}
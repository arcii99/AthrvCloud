//FormAI DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// encryption key
const int key = 5;

// function to encrypt a message
char* encrypt(const char* message) {
    int len = strlen(message);
    char* encrypted_message = malloc(len + 1);
    for(int i = 0; i < len; i++) {
        encrypted_message[i] = message[i] + key;
    }
    encrypted_message[len] = '\0';
    return encrypted_message;
}

// function to decrypt a message
char* decrypt(const char* message) {
    int len = strlen(message);
    char* decrypted_message = malloc(len + 1);
    for(int i = 0; i < len; i++) {
        decrypted_message[i] = message[i] - key;
    }
    decrypted_message[len] = '\0';
    return decrypted_message;
}

int main() {
    char message[MAX_LEN];
    printf("Enter message: ");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';
    
    char* encrypted = encrypt(message);
    printf("Encrypted message: %s\n", encrypted);
    
    char* decrypted = decrypt(encrypted);
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    
    return 0;
}
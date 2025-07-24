//FormAI DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Encryption function
void encrypt(char* message, char* key) {
    srand(time(NULL));  // Random seed
    
    int message_len = strlen(message);
    int key_len = strlen(key);
    
    char encrypted_message[message_len];
    
    // Create a random number sequence
    int nums[key_len];
    for (int i = 0; i < key_len; i++) {
        nums[i] = rand() % 10;
    }
    
    // Iterate over the message and key to encrypt the message
    for (int i = 0; i < message_len; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_len] ^ nums[i % key_len];
    }
    
    printf("Encrypted Message: %s\n", encrypted_message);
}

int main() {
    char message[100];
    char key[100];
    
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;  // Remove newline from message
    
    printf("Enter key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0;  // Remove newline from key
    
    encrypt(message, key);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Function to perform encryption
char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted_message = (char*) malloc(length * sizeof(char));
    
    // Encryption algorithm
    for(int i = 0; i < length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
        else {
            encrypted_message[i] = message[i];
        }
    }
    return encrypted_message;
}

int main() {
    char message[100];
    int key;

    // Get message and key from user
    printf("Enter the message to be encrypted: ");
    gets(message);

    printf("Enter the key value: ");
    scanf("%d", &key);
    
    // Encrypt message
    char* encrypted_message = encrypt(message, key);

    // Display encrypted message
    printf("\nEncrypted message: %s\n", encrypted_message);

    // Free dynamically allocated memory
    free(encrypted_message);
    
    return 0;
}
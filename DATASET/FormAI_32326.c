//FormAI DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
void encrypt(char* message, int key) {
    int n = strlen(message);

    // Iterate through each character of the message
    for(int i=0; i<n; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            // Shift the character by key positions
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            // Shift the character by key positions
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

// Decryption function
void decrypt(char* message, int key) {
    int n = strlen(message);

    // Iterate through each character of the message
    for(int i=0; i<n; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            // Shift the character by key positions
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            // Shift the character by key positions
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}

int main() {
    char message[100];
    int key;

    // Get the message and key from the user
    printf("Enter the message : ");
    fgets(message, 100, stdin);
    printf("Enter the key : ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message : %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message : %s\n", message);

    return 0;
}
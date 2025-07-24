//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char message[1000];
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Removing newline character from the input
    
    srand(time(0)); // Initializing random seed
    
    // Generating a random key
    int key = rand() % 100000 + 1000;
    
    // Encryption process
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] + key;
    }
    
    // Printing the encrypted message and key
    printf("Encrypted message: %s\nKey: %d\n", message, key);
    
    // Decryption process
    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] - key;
    }

    printf("Decrypted message: %s\n", message);
    
    return 0;
}
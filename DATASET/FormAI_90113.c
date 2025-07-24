//FormAI DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int key, i;
    
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    
    printf("Enter a key: ");
    scanf("%d", &key);
    
    // Encryption
    for (i = 0; message[i] != '\0'; i++) {
        message[i] += key;
    }
    
    printf("Encrypted message: %s\n", message);
    
    // Decryption - using the same key
    for (i = 0; message[i] != '\0'; i++) {
        message[i] -= key;
    }
    
    printf("Decrypted message: %s\n", message);
    
    return 0;
}
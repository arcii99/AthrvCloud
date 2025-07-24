//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 'S'

int main() {
    char message[100];
    printf("Enter message to encrypt:\n");
    fgets(message, sizeof(message), stdin);

    // Encryption process
    int i;
    for(i = 0; i < strlen(message); i++) {
        message[i] ^= KEY;
    }

    printf("Encrypted message: %s\n", message);

    // Decryption process
    for(i = 0; i < strlen(message); i++) {
        message[i] ^= KEY;
    }

    printf("Decrypted message: %s\n", message);

    return 0;
}
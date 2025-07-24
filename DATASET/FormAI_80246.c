//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    char key[100];
    char encrypted[100];
    char decrypted[100];

    printf("Enter your message to be encrypted: \n");
    fgets(message, 100, stdin);

    printf("Enter your key: \n");
    fgets(key, 100, stdin);

    // Remove newline characters from input
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encrypting message with the key
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = message[i] ^ key[i % strlen(key)];
    }

    printf("The encrypted message is: %s\n", encrypted);

    // Decrypting encrypted message with the key
    for (int i = 0; i < strlen(encrypted); i++) {
        decrypted[i] = encrypted[i] ^ key[i % strlen(key)];
    }

    printf("The decrypted message is: %s\n", decrypted);

    return 0;
}
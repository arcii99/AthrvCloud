//FormAI DATASET v1.0 Category: modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    int key, choice, i;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a key: ");
    scanf("%d", &key);

    printf("\n1. Encrypt\n2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEncrypting message...\n");

        for (i = 0; message[i] != '\0'; i++) {
            if (message[i] != ' ') {
                message[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
        }

        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        printf("\nDecrypting message...\n");

        for (i = 0; message[i] != '\0'; i++) {
            if (message[i] != ' ') {
                message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
            }
        }

        printf("Decrypted message: %s\n", message);
    } else {
        printf("\nInvalid choice. Exiting...\n");
        exit(0);
    }

    return 0;
}
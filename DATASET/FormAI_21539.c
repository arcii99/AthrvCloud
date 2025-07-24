//FormAI DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>

int main() {
    char message[] = "You are my sunshine, my only sunshine";
    char key[] = "forever";
    int messageLen = strlen(message), keyLen = strlen(key), i, j;
    char encrypted[100], decrypted[100];

    printf("My dearest love, I have a secret message for you:\n\n");

    printf("Original Message: %s\n", message);

    // Encrypting the message
    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        encrypted[i] = ((message[i] + key[j]) % 26) + 'A';
    }
    encrypted[i] = '\0';

    printf("\nEncrypted Message: %s\n", encrypted);

    // Decrypting the message
    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        decrypted[i] = (((encrypted[i] - key[j]) + 26) % 26) + 'A';
    }
    decrypted[i] = '\0';

    printf("\nDecrypted Message: %s\n", decrypted);

    printf("\nYou are the key to my heart, my sweet encrypted message for you means \'forever together\'.\n");

    return 0;
}
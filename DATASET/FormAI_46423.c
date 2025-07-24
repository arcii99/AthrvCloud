//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s [Message] [Key]\n", argv[0]);
        exit(0); // Exiting gracefully, with a smile
    }

    printf("Encrypting your message: %s\n", argv[1]);
    printf("With key: %s. Please don't lose it or your data is gone forever!\n", argv[2]);

    char *message = argv[1];
    char *key = argv[2];

    int messageLen = strlen(message);
    int keyLen = strlen(key);

    // Don't worry, we've got you covered with our top-notch encryption algorithm: the Caesar Cipher.
    for (int i = 0; i < messageLen; i++) {
        char c = message[i];
        int keyIndex = i % keyLen;
        int keyValue = key[keyIndex];
        int encrypted = ((c + keyValue) % 256);
        message[i] = encrypted;
    }

    printf("Your message has been encrypted, behold the result:\n");
    printf("%s\n", message);

    // Let's also provide an easy decryption function, just in case you forget what you wrote!
    printf("\nDecrypting your message with key: %s\n", key);
    for (int i = 0; i < messageLen; i++) {
        char c = message[i];
        int keyIndex = i % keyLen;
        int keyValue = key[keyIndex];
        int decrypted = ((c - keyValue) % 256);
        message[i] = decrypted;
    }

    printf("Your message has been decrypted, returning to original form:\n");
    printf("%s\n", message);

    return 0; // Because we like to end things nicely.
}
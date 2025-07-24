//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    unsigned char result[SHA256_DIGEST_LENGTH];
    char message[100];

    printf("Enter message to hash: ");
    fgets(message, 100, stdin);

    SHA256(message, strlen(message), result);

    printf("Hashed message: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define SHA256_DIGEST_SIZE 32
#define MAX_MESSAGE_SIZE 1024

// Function that generates SHA-256 hash of given message
void sha256(char *message, unsigned char *digest) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final(digest, &sha256);
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    printf("Enter message to hash: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Generate SHA-256 hash of message
    unsigned char digest[SHA256_DIGEST_SIZE];
    sha256(message, digest);

    // Print hash in hexadecimal format
    printf("SHA-256 hash of message:\n");
    int i;
    for(i = 0; i < SHA256_DIGEST_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// function to generate SHA256 hash
char* generateSHA256Hash(char* message) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char *outputBuffer = (char*) malloc(SHA256_DIGEST_LENGTH*2+1);

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final(hash, &sha256);

    for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;

    return outputBuffer;
}

int main() {
    char *message = "Hello World!";
    char *hash = generateSHA256Hash(message);

    printf("Message: %s\n", message);
    printf("Hash: %s\n", hash);

    return 0;
}
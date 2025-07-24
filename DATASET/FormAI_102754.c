//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define BUFFERSIZE 1024

int main() {

    // Sample string to hash
    char stringToHash[] = "This is a test string";

    // Hashing buffer
    unsigned char hashBuffer[SHA256_DIGEST_LENGTH];

    // Initialize SHA-256 context
    SHA256_CTX context;
    SHA256_Init(&context);

    // Hash the string
    SHA256_Update(&context, stringToHash, strlen(stringToHash));
    SHA256_Final(hashBuffer, &context);

    printf("The hashed value of the string is:\n");

    // Print the hashed value
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hashBuffer[i]);
    }

    printf("\n");

    return 0;
}
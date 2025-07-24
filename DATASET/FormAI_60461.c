//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: expert-level
/**
 * A unique cryptographic hash function implementation in C.
 * This hash function is a combination of SHA-256 and XOR operator.
 *
 * This code is meant for educational purposes ONLY.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>

#define MAX_MESSAGE_LENGTH 1000

// Function prototypes
void sha256(unsigned char *input, size_t length, unsigned char *output);
void xor_hash(unsigned char *input, size_t length, unsigned char *output);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    unsigned char sha_output[SHA256_DIGEST_LENGTH];
    unsigned char hash_output[SHA256_DIGEST_LENGTH];
    
    printf("Enter a message to hash: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove trailing newline from fgets
    
    // Compute SHA-256 hash of message
    sha256((unsigned char*)message, strlen(message), sha_output);
    
    // Compute XOR hash of SHA-256 hash
    xor_hash(sha_output, SHA256_DIGEST_LENGTH, hash_output);
    
    // Print out original message and hash value
    printf("Message: %s\nHash: ", message);
    for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash_output[i]);
    }
    printf("\n");
    
    return 0;
}

/**
 * Compute SHA-256 hash of input string.
 *
 * @param input: input string to be hashed
 * @param length: length of input string
 * @param output: buffer to store hash output (must be at least SHA256_DIGEST_LENGTH bytes)
 */
void sha256(unsigned char *input, size_t length, unsigned char *output) {
    SHA256_CTX context;
    SHA256_Init(&context);
    SHA256_Update(&context, input, length);
    SHA256_Final(output, &context);
}

/**
 * Compute XOR hash of input byte array.
 *
 * @param input: input byte array to be hashed
 * @param length: length of input byte array
 * @param output: buffer to store hash output (must be at least SHA256_DIGEST_LENGTH bytes)
 */
void xor_hash(unsigned char *input, size_t length, unsigned char *output) {
    for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
        output[i] = input[i] ^ 0xFF;
    }
}
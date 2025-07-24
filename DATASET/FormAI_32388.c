//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to calculate SHA256 hash recursively
void sha256_recursive(const char *message, unsigned char hash[SHA256_DIGEST_LENGTH], int depth)
{
    // Base case: depth is 0, hash the message
    if (depth == 0) {
        SHA256((const unsigned char *) message, strlen(message), hash);
        return;
    }

    // Recursive case: split the message in half, hash both halves and concatenate the hashes
    int message_length = strlen(message);
    int half_length = message_length / 2;
    char first_half[half_length + 1];
    char second_half[half_length + 1];
    memcpy(first_half, message, half_length);
    memcpy(second_half, message + half_length, half_length);
    first_half[half_length] = '\0';
    second_half[half_length] = '\0';

    unsigned char first_hash[SHA256_DIGEST_LENGTH], second_hash[SHA256_DIGEST_LENGTH];
    sha256_recursive(first_half, first_hash, depth - 1);
    sha256_recursive(second_half, second_hash, depth - 1);

    unsigned char combined_hash[SHA256_DIGEST_LENGTH * 2];
    memcpy(combined_hash, first_hash, SHA256_DIGEST_LENGTH);
    memcpy(combined_hash + SHA256_DIGEST_LENGTH, second_hash, SHA256_DIGEST_LENGTH);

    SHA256(combined_hash, SHA256_DIGEST_LENGTH * 2, hash);
}

// Example usage
int main()
{
    const char *message = "hello world";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    sha256_recursive(message, hash, 2);

    char hash_str[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_str[i * 2], "%02x", hash[i]);
    }
    hash_str[SHA256_DIGEST_LENGTH * 2] = '\0';

    printf("Message: %s\n", message);
    printf("Hash:    %s\n", hash_str);
    return 0;
}
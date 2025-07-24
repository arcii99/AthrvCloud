//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_STR_LEN 1024

int main(void) {
    char input[MAX_STR_LEN], output[SHA256_DIGEST_LENGTH * 2 + 1];
    int i;

    // Get user input
    printf("Enter a string to hash: ");
    fgets(input, MAX_STR_LEN, stdin);
    input[strcspn(input, "\n")] = 0;

    // Initialize SHA-256 context
    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    // Update hash with user input
    SHA256_Update(&ctx, input, strlen(input));

    // Generate hash
    SHA256_Final(output, &ctx);
    output[SHA256_DIGEST_LENGTH * 2] = '\0';

    // Print hash
    printf("Hash of '%s' using SHA-256:\n", input);
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}
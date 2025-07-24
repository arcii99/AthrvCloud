//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main() {

    // Input message
    char message[] = "Grateful hash function example!";

    // Initialize OpenSSL hash function
    EVP_MD_CTX *ctx;
    const EVP_MD *md;
    md = EVP_sha256(); // Using SHA-256 algorithm
    ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, NULL);

    // Update hash with message
    EVP_DigestUpdate(ctx, message, strlen(message));

    // Finalize hash and output result
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    EVP_DigestFinal_ex(ctx, md_value, &md_len);

    printf("Message: %s\n", message);
    printf("Hash: ");
    for (int i = 0; i < md_len; i++) {
        printf("%02x", md_value[i]);
    }
    printf("\n");

    // Clean up
    EVP_MD_CTX_free(ctx);

    return 0;
}
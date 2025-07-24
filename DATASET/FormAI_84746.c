//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define HASH_SIZE 64

// Function to generate cryptographic hash
char *generate_hash(char *str) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char hash_val[HASH_SIZE];
    char *hash_str = (char*) malloc(2 * HASH_SIZE+1);
    int i;

    // Initialize OpenSSL library
    OpenSSL_add_all_digests();
    // Selecting SHA-512 for generating the hash
    md = EVP_get_digestbyname("SHA512");
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, str, strlen(str));
    EVP_DigestFinal_ex(mdctx, hash_val, NULL);
    EVP_MD_CTX_free(mdctx);

    // Convert binary hash to hexadecimal string
    for(i = 0; i < HASH_SIZE; i++) {
        sprintf(hash_str + (i * 2), "%02x", hash_val[i]);
    }
    hash_str[2 * HASH_SIZE] = '\0';

    return hash_str;
}

int main() {
    char *str, *hash;
    printf("Enter a string to generate hash: ");
    scanf("%ms", &str);

    hash = generate_hash(str);
    printf("\nGenerated hash: %s\n", hash);

    free(str);
    free(hash);

    return 0;
}
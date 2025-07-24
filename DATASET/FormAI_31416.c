//FormAI DATASET v1.0 Category: Password management ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_PASSWORD_LENGTH 50

unsigned char *generate_hash(unsigned char *password)
{
    // Set up SHA256 hash
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char *hash = malloc(EVP_MAX_MD_SIZE);
    unsigned int hash_length;

    mdctx = EVP_MD_CTX_new();
    md = EVP_sha256();

    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, password, strlen(password));
    EVP_DigestFinal_ex(mdctx, hash, &hash_length);

    EVP_MD_CTX_free(mdctx);
    return hash;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    unsigned char *hash = generate_hash(password);
    printf("Hashed password: ");
    for (int i = 0; i < EVP_MAX_MD_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    free(hash);
    return 0;
}
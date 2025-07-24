//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h> // OpenSSL library

void hash_callback(int status, void *data) {
    EVP_MD_CTX *ctx = (EVP_MD_CTX *)data;
    unsigned char md[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    EVP_DigestFinal_ex(ctx, md, &md_len); // finalizing the hash
    printf("Hash value is: ");
    for(int i=0; i<md_len; i++)
        printf("%02x", md[i]); // printing the hash in Hex format
    printf("\n");
    EVP_MD_CTX_free(ctx); // freeing the memory occupied by the context
}

void calculate_hash(char *input, EVP_MD_CTX *ctx) {
    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL); // selecting the hash algorithm
    EVP_DigestUpdate(ctx, input, strlen(input)); // input data to hash
}

int main() {
    char input[256];
    fputs("Enter the input to be hashed: ", stdout);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // removing the newline character
    EVP_MD_CTX *ctx = EVP_MD_CTX_new(); // allocating memory for the context
    calculate_hash(input, ctx); // calculating the hash
    free(ctx); // releasing the memory occupied by the context
    printf("Hash calculation is complete!\n");
    return 0;
}
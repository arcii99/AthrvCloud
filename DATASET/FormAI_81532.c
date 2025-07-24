//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// Function to create a cryptographic hash of a given string
int hash_string(const char *input_string, unsigned char *hash, const int hash_len, const EVP_MD *md) {
    EVP_MD_CTX *mdctx;
    int result = 0;

    // Allocate memory for message digest context and initialize it
    if((mdctx = EVP_MD_CTX_new()) == NULL) {
        printf("Error: EVP_MD_CTX_new failed.\n");
        return 0;
    }

    // Initialize message digest context with the corresponding algorithm
    if(1 != EVP_DigestInit_ex(mdctx, md, NULL)) {
        printf("Error: EVP_DigestInit_ex failed.\n");
        EVP_MD_CTX_free(mdctx);
        return 0;
    }

    // Add the input string into the message digest context
    if(1 != EVP_DigestUpdate(mdctx, input_string, strlen(input_string))) {
        printf("Error: EVP_DigestUpdate failed.\n");
        EVP_MD_CTX_free(mdctx);
        return 0;
    }

    // Finalize the message digest context and retrieve the hash value
    if(1 != EVP_DigestFinal_ex(mdctx, hash, (unsigned int *)&hash_len)) {
        printf("Error: EVP_DigestFinal_ex failed.\n");
        EVP_MD_CTX_free(mdctx);
        return 0;
    }

    // Free the message digest context
    EVP_MD_CTX_free(mdctx);

    // Set the result to the length of the hash
    result = hash_len;

    return result;
}

int main(void) {
    char input_string[100];
    unsigned char hash_value[EVP_MAX_MD_SIZE];
    int hash_len = 0;

    // Initialize the OpenSSL library
    OpenSSL_add_all_digests();

    // Prompt the user to enter a string to be hashed
    printf("Enter a string to be hashed: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = 0;

    // Compute the SHA-256 hash of the input string
    hash_len = hash_string(input_string, hash_value, EVP_MAX_MD_SIZE, EVP_sha256());

    // Print the hash value in hexadecimal format
    printf("Hash value (SHA-256): ");
    for(int i = 0; i < hash_len; i++) {
        printf("%02x", hash_value[i]);
    }
    printf("\n");

    // Clean up the OpenSSL library
    EVP_cleanup();

    return 0;
}
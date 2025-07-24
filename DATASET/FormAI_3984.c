//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to calculate SHA256 hash of a given string
unsigned char* calculateSHA256(const unsigned char* string, size_t length) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    unsigned char* digest = (unsigned char*)malloc(EVP_MD_size(EVP_sha256()));
    unsigned int digestLength = 0;
    
    EVP_DigestInit_ex(context, EVP_sha256(), NULL);
    EVP_DigestUpdate(context, string, length);
    EVP_DigestFinal_ex(context, digest, &digestLength);
    EVP_MD_CTX_free(context);
    
    return digest;
}

int main() {
    char* message = "Hello, world!";
    size_t messageLength = strlen(message);
    
    // Calculate SHA256 hash of the message
    unsigned char* digest = calculateSHA256((unsigned char*)message, messageLength);
    
    // Print the hash in hexadecimal format
    for (int i = 0; i < EVP_MD_size(EVP_sha256()); i++) {
        printf("%02x ", digest[i]);
    }
    printf("\n");
    
    free(digest);
    return 0;
}
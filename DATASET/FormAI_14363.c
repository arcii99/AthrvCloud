//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_INPUT_LENGTH 1000

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter the string to be hashed:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    EVP_MD_CTX *md_ctx;
    const EVP_MD *md;
    unsigned char output[EVP_MAX_MD_SIZE];
    unsigned int output_length;

    // Initialize the message digest context
    md_ctx = EVP_MD_CTX_create();
    // Specify the hash function
    md = EVP_get_digestbyname("SHA256");
    // Initialize the message digest operation
    EVP_DigestInit_ex(md_ctx, md, NULL);
    // Update the message digest with the input string
    EVP_DigestUpdate(md_ctx, input, strlen(input));
    // Finalize the message digest and store the output
    EVP_DigestFinal_ex(md_ctx, output, &output_length);
    // Free the message digest context
    EVP_MD_CTX_destroy(md_ctx);

    printf("The hash of the string is:\n");
    for(int i=0; i<output_length; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
    
    return 0;
}
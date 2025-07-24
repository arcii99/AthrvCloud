//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred\n");
    exit(1);
}

int main(void)
{
    EVP_MD_CTX *md_ctx;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    char plaintext[] = "Hello, world!";
    int plaintext_len = strlen(plaintext);

    /* Initialize context */
    md_ctx = EVP_MD_CTX_new();
    if (md_ctx == NULL)
        handleErrors();

    /* Hash the plaintext */
    if (EVP_DigestInit_ex(md_ctx, EVP_sha256(), NULL) != 1)
        handleErrors();
    if (EVP_DigestUpdate(md_ctx, plaintext, plaintext_len) != 1)
        handleErrors();
    if (EVP_DigestFinal_ex(md_ctx, md_value, &md_len) != 1)
        handleErrors();

    /* Print out the hash */
    printf("Hash value: ");
    for (int i = 0; i < md_len; i++) {
        printf("%02x", md_value[i]);
    }
    printf("\n");

    /* Clean up context */
    if (md_ctx != NULL)
        EVP_MD_CTX_free(md_ctx);

    return 0;
}
//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <openssl/evp.h>

void create_watermark(char *identity_data, char *public_key, char *watermark)
{
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    OpenSSL_add_all_digests();

    md = EVP_get_digestbyname("sha256");
    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, identity_data, strlen(identity_data));
    EVP_DigestUpdate(mdctx, public_key, strlen(public_key));
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_destroy(mdctx);

    //encrypt the md_value using public_key and save the result into watermark variable
    //TODO: add encryption code here

    printf("Watermark created!\n");
}

int main()
{
    char identity_data[] = "johndoe@example.com";
    char public_key[] = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCpsZ8B9AgS6bIOsvNtDGeAL5gNpJgrWv/GkXHhzo7YoT0E+GQwupbpzX9nXoE1Mx4ASxPe5r/ZReIkyrVG1Fiav7hRRvY6+mXo5ku4rd+DCtqcnkC9nW9/VGKMk8aeqq9Ndc3GUivVSZM9W6UsgncD8MZ3heZV4j7Yy4QDvJJwIDAQAB";
    char watermark[128];

    create_watermark(identity_data, public_key, watermark);

    return 0;
}
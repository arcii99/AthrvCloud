//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void print_hash(unsigned char *hash, int len)
{
    int i;
    
    for (i = 0; i < len; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main()
{
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char hash[EVP_MAX_MD_SIZE];
    int hash_len, i;
    char message[80] = "mysecretmessage";
    
    md = EVP_get_digestbyname("SHA256");
    
    if (md == NULL)
    {
        printf("Unknown message digest\n");
        return 1;
    }
    
    mdctx = EVP_MD_CTX_new();
    
    EVP_DigestInit_ex(mdctx, md, NULL);
    
    EVP_DigestUpdate(mdctx, message, strlen(message));
    
    EVP_DigestFinal_ex(mdctx, hash, &hash_len);
    
    EVP_MD_CTX_free(mdctx);
    
    printf("SHA256 Hash: ");
    print_hash(hash, hash_len);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char* argv[]) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    int md_len, i;

    if (argc != 3) {
        printf("Usage: %s <hash type> <input string>\n", argv[0]);
        exit(1);
    }

    OpenSSL_add_all_digests();

    md = EVP_get_digestbyname(argv[1]);

    if (md == NULL) {
        printf("Unknown message digest %s\n", argv[1]);
        exit(1);
    }

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, argv[2], strlen(argv[2]));
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);

    printf("Input:\t%s\n", argv[2]);
    printf("Hash:\t");
    for (i = 0; i < md_len; i++) {
        printf("%02x", md_value[i]);
    }
    printf("\n");

    return 0;
}
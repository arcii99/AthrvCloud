//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void hash_file(char *filename, unsigned char *md_value, unsigned int *md_len) {
    FILE *file = fopen(filename, "rb");
    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(md_ctx, EVP_sha256(), NULL);
    unsigned char buffer[1024];
    size_t read_bytes;
    while ((read_bytes = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        EVP_DigestUpdate(md_ctx, buffer, read_bytes);
    }
    EVP_DigestFinal_ex(md_ctx, md_value, md_len);
    EVP_MD_CTX_free(md_ctx);
    fclose(file);
}

void print_hex(unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    hash_file(filename, md_value, &md_len);
    printf("SHA256 hash of file %s:\n", filename);
    print_hex(md_value, md_len);
    return 0;
}
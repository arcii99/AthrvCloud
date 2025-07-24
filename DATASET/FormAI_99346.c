//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_BUF_SIZE 1024

void calculate_sha256(const char *file_path, unsigned char *hash)
{
    FILE *file = fopen(file_path, "rb");
    if (!file)
    {
        printf("Error: Unable to open file.\n");
        return;
    }

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    const size_t buf_size = 65536;
    unsigned char *buffer = malloc(buf_size);
    size_t bytes_read = 0;
    if (!buffer)
    {
        printf("Error: Out of memory.\n");
        fclose(file);
        return;
    }

    while ((bytes_read = fread(buffer, 1, buf_size, file)))
    {
        SHA256_Update(&sha256, buffer, bytes_read);
    }
    SHA256_Final(hash, &sha256);

    fclose(file);
    free(buffer);
}
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s file_path\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    unsigned char hash_buffer[SHA256_DIGEST_LENGTH];
    memset(hash_buffer, 0, SHA256_DIGEST_LENGTH);

    calculate_sha256(file_path, hash_buffer);

    printf("SHA256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x ", hash_buffer[i]);
    }
    printf("\n");
    return 0;
}
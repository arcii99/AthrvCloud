//FormAI DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BUF_SIZE 4096

void encrypt_file(const char *input_filename, const char *output_filename, const unsigned char *key) {
    FILE *ifp, *ofp;
    unsigned char iv[AES_BLOCK_SIZE];
    AES_KEY aes_key;
    size_t bytes_read;
    unsigned char inbuf[BUF_SIZE], outbuf[BUF_SIZE];

    ifp = fopen(input_filename, "rb");
    if (!ifp) {
        printf("Failed to open input file.\n");
        return;
    }

    ofp = fopen(output_filename, "wb");
    if (!ofp) {
        printf("Failed to open output file.\n");
        fclose(ifp);
        return;
    }

    // Generate a random IV
    srand(time(NULL));
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        iv[i] = rand() % 256;
    }

    fwrite(iv, 1, AES_BLOCK_SIZE, ofp);

    // Set up encryption key
    AES_set_encrypt_key(key, 128, &aes_key);

    // Encrypt file
    while ((bytes_read = fread(inbuf, 1, BUF_SIZE, ifp)) > 0) {
        AES_cbc_encrypt(inbuf, outbuf, bytes_read, &aes_key, iv, AES_ENCRYPT);
        fwrite(outbuf, 1, bytes_read, ofp);
    }

    fclose(ifp);
    fclose(ofp);

    printf("File encrypted successfully.\n");
}

int main(int argc, char *argv[]) {
    const char *input_filename;
    const char *output_filename;
    unsigned char key[] = "SUPERSECRETKEY";

    if (argc < 3) {
        printf("Usage: file_encryptor input_file output_file\n");
        return 1;
    }

    input_filename = argv[1];
    output_filename = argv[2];

    encrypt_file(input_filename, output_filename, key);
    return 0;
}
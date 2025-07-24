//FormAI DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

int encrypt_file(const char *input_filename, const char *output_filename, const char *key) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Error: Couldn't open input file %s\n", input_filename);
        return -1;
    }
    
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error: Couldn't open output file %s\n", output_filename);
        fclose(input_file);
        return -1;
    }
    
    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, 128, &aes_key) != 0) {
        printf("Error: Couldn't set AES encryption key\n");
        fclose(input_file);
        fclose(output_file);
        return -1;
    }
    
    unsigned char data_in[AES_BLOCK_SIZE];
    unsigned char data_out[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0, AES_BLOCK_SIZE);
    
    int bytes_read = 0;
    int bytes_written = 0;
    while ((bytes_read = fread(data_in, 1, AES_BLOCK_SIZE, input_file)) > 0) {
        AES_cbc_encrypt(data_in, data_out, bytes_read, &aes_key, iv, AES_ENCRYPT);
        bytes_written = fwrite(data_out, 1, bytes_read, output_file);
        if (bytes_written < bytes_read) {
            printf("Error: Couldn't write entire block to output file\n");
            fclose(input_file);
            fclose(output_file);
            return -1;
        }
    }
    
    fclose(input_file);
    fclose(output_file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return -1;
    }
    
    int result = encrypt_file(argv[1], argv[2], argv[3]);
    if (result != 0) {
        printf("Encryption failed with error code %d\n", result);
        return -1;
    }
    
    printf("Encryption succeeded!\n");
    return 0;
}
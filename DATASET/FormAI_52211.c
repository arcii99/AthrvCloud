//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BUFFER_SIZE 4096

void encrypt_file(char* input_file, char* output_file, unsigned char* key, unsigned char* iv) {
    FILE *in_file, *out_file;
    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;
    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);

    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", input_file);
        exit(1);
    }
    
    out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        fclose(in_file);
        fprintf(stderr, "Error: Could not open output file %s\n", output_file);
        exit(1);
    }
    
    while (1) {
        bytes_read = fread(buffer, 1, BUFFER_SIZE, in_file);
        if (bytes_read == 0) {
            break;
        }
        if (bytes_read % 16 != 0) {
            int pad_length = 16 - (bytes_read % 16);
            memset(buffer + bytes_read, pad_length, pad_length);
            bytes_read += pad_length;
        }
        AES_cbc_encrypt(buffer, buffer, bytes_read, &aesKey, iv, AES_ENCRYPT);
        fwrite(buffer, 1, bytes_read, out_file);
    }
    
    fclose(in_file);
    fclose(out_file);
}

void decrypt_file(char* input_file, char* output_file, unsigned char* key, unsigned char* iv) {
    FILE *in_file, *out_file;
    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);

    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", input_file);
        exit(1);
    }
    
    out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        fclose(in_file);
        fprintf(stderr, "Error: Could not open output file %s\n", output_file);
        exit(1);
    }
    
    while (1) {
        bytes_read = fread(buffer, 1, BUFFER_SIZE, in_file);
        if (bytes_read == 0) {
            break;
        }
        AES_cbc_encrypt(buffer, buffer, bytes_read, &aesKey, iv, AES_DECRYPT);
        int pad_length = buffer[bytes_read - 1];
        fwrite(buffer, 1, bytes_read - pad_length, out_file);
    }
    
    fclose(in_file);
    fclose(out_file);
}

int main(void) {
    unsigned char key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    unsigned char iv[] = {0x71, 0x8c, 0x7d, 0x7e, 0x8c, 0x9c, 0xbc, 0x5c, 0x9f, 0x14, 0x86, 0x98, 0xbf, 0xdb, 0xad, 0xa1};
    char input_file[] = "input.txt";
    char encrypted_file[] = "encrypted.bin";
    char decrypted_file[] = "decrypted.txt";

    encrypt_file(input_file, encrypted_file, key, iv);
    printf("File successfully encrypted!\n");

    decrypt_file(encrypted_file, decrypted_file, key, iv);
    printf("File successfully decrypted!\n");

    return 0;
}
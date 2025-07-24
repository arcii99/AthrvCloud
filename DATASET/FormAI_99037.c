//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void encrypt_data(unsigned char *key, unsigned char *iv, unsigned char *input, unsigned char *output, int length) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(input, output, length, &aes_key, iv, AES_ENCRYPT);
}

void decrypt_data(unsigned char *key, unsigned char *iv, unsigned char *input, unsigned char *output, int length) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(input, output, length, &aes_key, iv, AES_DECRYPT);
}

int main() {
    unsigned char key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    unsigned char iv[16] = {0x00};
    unsigned char input[] = "hello world";
    int input_len = strlen(input);
    unsigned char *enc_output = (unsigned char*) malloc(input_len*sizeof(unsigned char));
    unsigned char *dec_output = (unsigned char*) malloc(input_len*sizeof(unsigned char));
    
    encrypt_data(key, iv, input, enc_output, input_len);
    decrypt_data(key, iv, enc_output, dec_output, input_len);
    
    printf("Input: %s\n", input);
    printf("Encrypted Output: ");
    for(int i=0; i<input_len; i++) {
        printf("%02x ", enc_output[i]);
    }
    printf("\nDecrypted Output: %s\n", dec_output);
    
    free(enc_output);
    free(dec_output);
    
    return 0;
}
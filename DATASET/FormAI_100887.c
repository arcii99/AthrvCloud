//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024
#define SALT_SIZE 8
#define KEY_SIZE 32
#define TAG_SIZE 16

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *aad,
            int aad_len, unsigned char *key, unsigned char *iv,
            unsigned char *ciphertext, unsigned char *tag){
    EVP_CIPHER_CTX *ctx;
    int len, ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())){
        return -1;
    }

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)){
        return -1;
    }

    if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 16, NULL)){
        return -1;
    }

    if(1 != EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv)){
        return -1;
    }

    if(aad && aad_len > 0){
        if(1 != EVP_EncryptUpdate(ctx, NULL, &len, aad, aad_len)){
            return -1;
        }
    }

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)){
        return -1;
    }
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)){
        return -1;
    }
    ciphertext_len += len;

    if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, TAG_SIZE, tag)){
        return -1;
    }

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *aad,
            int aad_len, unsigned char *tag, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext){
    EVP_CIPHER_CTX *ctx;
    int len, plaintext_len, ret;
    uint8_t btag[TAG_SIZE];

    if(!(ctx = EVP_CIPHER_CTX_new())){
        return -1;
    }

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)){
        return -1;
    }

    if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 16, NULL)){
        return -1;
    }

    if(1 != EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv)){
        return -1;
    }

    if(aad && aad_len > 0){
        if(1 != EVP_DecryptUpdate(ctx, NULL, &len, aad, aad_len)){
            return -1;
        }
    }

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)){
        return -1;
    }
    plaintext_len = len;

    if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, TAG_SIZE, tag)){
        return -1;
    }

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)){
        return -1;
    }
    plaintext_len += len;

    ret = EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, TAG_SIZE, btag);
    if(ret < 0){
        return -1;
    }
    if(memcmp(tag, btag, TAG_SIZE) != 0){
        return -1;
    }

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char **argv){
    FILE *fp;
    unsigned char *key, *plaintext, *aad, *tag, *ciphertext, *iv;
    uint8_t bkey[KEY_SIZE], baad[BUFFER_SIZE], btag[TAG_SIZE], biv[SALT_SIZE];
    int len, ciphertext_len, plaintext_len;
    memset(bkey, 0x76, KEY_SIZE);
    memset(baad, 0x11, BUFFER_SIZE);
    memset(biv, 0x47, SALT_SIZE);

    key = bkey;
    plaintext = (unsigned char *)"This is a secret message.";
    aad = baad;
    tag = btag;
    iv = biv;

    ciphertext = malloc(BUFFER_SIZE);
    memset(ciphertext, 0, BUFFER_SIZE);
    ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), aad, strlen((char *)aad), key, iv, ciphertext, tag);
    if(ciphertext_len < 0){
        printf("Encryption failed\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen("encrypted.bin", "wb");
    fwrite(ciphertext, 1, ciphertext_len, fp);
    fclose(fp);

    fp = fopen("tag.bin", "wb");
    fwrite(tag, 1, TAG_SIZE, fp);
    fclose(fp);

    unsigned char *encrypted_text = NULL;
    long enc_file_size;
    FILE *enc_file = fopen("encrypted.bin", "r");
    if (enc_file)
    {
        fseek(enc_file, 0, SEEK_END);
        enc_file_size = ftell(enc_file);
        fseek(enc_file, 0, SEEK_SET);
        encrypted_text = malloc(enc_file_size);
        if (encrypted_text)
        {
            fread(encrypted_text, 1, enc_file_size, enc_file);
        }
        fclose(enc_file);
    }

    unsigned char *tag_text = NULL;
    long tag_file_size;
    FILE *tag_file = fopen("tag.bin", "r");
    if (tag_file)
    {
        fseek(tag_file, 0, SEEK_END);
        tag_file_size = ftell(tag_file);
        fseek(tag_file, 0, SEEK_SET);
        tag_text = malloc(tag_file_size);
        if (tag_text)
        {
            fread(tag_text, 1, tag_file_size, tag_file);
        }
        fclose(tag_file);
    }

    plaintext_len = BUFFER_SIZE;
    plaintext = malloc(BUFFER_SIZE);
    memset(plaintext, 0, BUFFER_SIZE);
    len = decrypt(encrypted_text, enc_file_size, aad, strlen((char *)aad), tag_text, key, iv, plaintext);
    if(len < 0){
        printf("Decryption failed\n");
        exit(EXIT_FAILURE);
    }
    plaintext_len = len;

    printf("Recovered plaintext is:\n");
    printf("%s\n", plaintext);

    exit(EXIT_SUCCESS);
}
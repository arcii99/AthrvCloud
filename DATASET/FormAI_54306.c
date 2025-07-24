//FormAI DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdbool.h>

struct settings {
    const EVP_CIPHER* cipher;
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
};

// Function to generate secure random key and IV
void generate_key_iv(struct settings* s) {
    RAND_bytes(s->key, EVP_CIPHER_key_length(s->cipher));
    RAND_bytes(s->iv, EVP_CIPHER_iv_length(s->cipher));
}

void encrypt_callback(EVP_CIPHER_CTX* ctx, const unsigned char* in, unsigned char* out, size_t len) {
    int outlen;
    EVP_EncryptUpdate(ctx, out, &outlen, in, len);
}

void decrypt_callback(EVP_CIPHER_CTX* ctx, const unsigned char* in, unsigned char* out, size_t len) {
    int outlen;
    EVP_DecryptUpdate(ctx, out, &outlen, in, len);
}

// Function to encrypt or decrypt data asynchronously
void async_encrypt_decrypt(bool encrypt, const unsigned char* in, unsigned char* out, size_t length, struct settings* s) {
    EVP_CIPHER_CTX* ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: Unable to create new cipher context\n");
        return;
    }

    EVP_CipherInit(ctx, s->cipher, s->key, s->iv, encrypt ? 1 : 0);

    EVP_CIPHER_CTX_set_padding(ctx, 1);

    if (encrypt) {
        EVP_EncryptInit_ex(ctx, NULL, NULL, s->key, s->iv);
        EVP_EncryptUpdate(ctx, out, (int*)&length, in, length);
        EVP_EncryptFinal_ex(ctx, out + length, (int*)&length);
    } else {
        EVP_DecryptInit_ex(ctx, NULL, NULL, s->key, s->iv);
        EVP_DecryptUpdate(ctx, out, (int*)&length, in, length);
        EVP_DecryptFinal_ex(ctx, out + length, (int*)&length);
    }

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char** argv) {
    struct settings s;
    s.cipher = EVP_get_cipherbyname("aes-256-cbc");
    if (!s.cipher) {
        fprintf(stderr, "Error: Unable to find AES-256-CBC cipher\n");
        return 1;
    }

    generate_key_iv(&s);

    const char* msg = "Hello, World!";
    size_t msg_len = strlen(msg) + 1; // include null terminator
    unsigned char* encrypted_msg = (unsigned char*)malloc(msg_len + EVP_MAX_BLOCK_LENGTH);
    unsigned char* decrypted_msg = (unsigned char*)malloc(msg_len);

    async_encrypt_decrypt(true, (unsigned char*)msg, encrypted_msg, msg_len, &s);
    async_encrypt_decrypt(false, encrypted_msg, decrypted_msg, msg_len, &s);

    printf("Original message: %s\n", msg);
    printf("Encrypted message: %s\n", encrypted_msg);
    printf("Decrypted message: %s\n", decrypted_msg);

    free(encrypted_msg);
    free(decrypted_msg);

    return 0;
}
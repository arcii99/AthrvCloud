//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void handleErrors()
{
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int main()
{
    int fd_in, fd_out;
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char buf[BUFFER_SIZE], ciphertext[BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH];
    int len, ciphertext_len;
    int read_size = BUFFER_SIZE;

    /* Set up the key and iv */
    if (!RAND_bytes(key, 32))
        handleErrors();

    if (!RAND_bytes(iv, 16))
        handleErrors();

    /* Open input and output files */
    fd_in = open("input.txt", O_RDONLY);
    if (fd_in == -1) {
        fprintf(stderr, "Failed to open input.txt.\n");
        exit(EXIT_FAILURE);
    }

    fd_out = open("output.enc", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
    if (fd_out == -1) {
        fprintf(stderr, "Failed to open output.enc.\n");
        exit(EXIT_FAILURE);
    }

    /* Encrypt the input file and write it to the output file */
    while (read_size == BUFFER_SIZE) {
        len = read(fd_in, buf, BUFFER_SIZE);
        if (len == -1) {
            fprintf(stderr, "Failed to read input file.\n");
            exit(EXIT_FAILURE);
        }
        read_size = len;

        ciphertext_len = encrypt(buf, len, key, iv, ciphertext);

        if (write(fd_out, ciphertext, ciphertext_len) != ciphertext_len) {
            fprintf(stderr, "Failed to write ciphertext to output file.\n");
            exit(EXIT_FAILURE);
        }
    }

    close(fd_in);
    close(fd_out);

    printf("Encryption successful.\n");
    return 0;
}
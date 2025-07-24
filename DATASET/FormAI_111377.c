//FormAI DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <openssl/evp.h>

#define BUF_SIZE 4096

void do_encrypt(const char *in_file, const char *out_file, const char *key, const char *iv) {
    EVP_CIPHER_CTX *ctx;
    int in_len, out_len, fd_in, fd_out;
    unsigned char in_data[BUF_SIZE], out_data[BUF_SIZE];
    
    if ((ctx = EVP_CIPHER_CTX_new()) == NULL) {
        printf("ERROR: EVP_CIPHER_CTX_new() failed\n");
        exit(EXIT_FAILURE);
    }
    
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        printf("ERROR: EVP_EncryptInit_ex() failed\n");
        exit(EXIT_FAILURE);
    }
    
    if ((fd_in = open(in_file, O_RDONLY)) == -1) {
        printf("ERROR: Unable to open input file '%s'\n", in_file);
        exit(EXIT_FAILURE);
    }
    
    if ((fd_out = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR)) == -1) {
        printf("ERROR: Unable to open output file '%s'\n", out_file);
        exit(EXIT_FAILURE);
    }
    
    while ((in_len = read(fd_in, in_data, BUF_SIZE)) > 0) {
        if (EVP_EncryptUpdate(ctx, out_data, &out_len, in_data, in_len) != 1) {
            printf("ERROR: EVP_EncryptUpdate() failed\n");
            exit(EXIT_FAILURE);
        }
        
        if (write(fd_out, out_data, out_len) != out_len) {
            printf("ERROR: Unable to write data to output file '%s'\n", out_file);
            exit(EXIT_FAILURE);
        }
    }
    
    if (in_len < 0) {
        printf("ERROR: Error while reading input file '%s'\n", in_file);
        exit(EXIT_FAILURE);
    }
    
    if (EVP_EncryptFinal_ex(ctx, out_data, &out_len) != 1) {
        printf("ERROR: EVP_EncryptFinal_ex() failed\n");
        exit(EXIT_FAILURE);
    }
    
    if (write(fd_out, out_data, out_len) != out_len) {
        printf("ERROR: Unable to write data to output file '%s'\n", out_file);
        exit(EXIT_FAILURE);
    }
    
    close(fd_in);
    close(fd_out);
    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("USAGE: %s <input file> <output file> <key> <iv>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *in_file = argv[1];
    char *out_file = argv[2];
    char *key = argv[3];
    char *iv = argv[4];
    
    do_encrypt(in_file, out_file, key, iv);
    
    printf("File %s successfully encrypted to %s\n", in_file, out_file);
    
    return EXIT_SUCCESS;
}
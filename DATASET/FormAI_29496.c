//FormAI DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xC3 // the key used for encryption

// function to encrypt or decrypt the given file using XOR cipher
void crypt_file(char *filename, unsigned char key) {
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    unsigned char buffer[file_size];

    fread(buffer, 1, file_size, fp);
    fseek(fp, 0L, SEEK_SET);

    for (int i = 0; i < file_size; i++) {
        buffer[i] = buffer[i] ^ key;
    }

    fwrite(buffer, 1, file_size, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];
    unsigned char key = KEY;

    crypt_file(filename, key);
    printf("File %s encrypted/decrypted with key 0x%02X\n", filename, key);

    return 0;
}
//FormAI DATASET v1.0 Category: modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BUF_SIZE 1024

void encrypt(char *input_filepath, char *output_filepath, unsigned char *key) {
    FILE *input_file = fopen(input_filepath, "rb");
    FILE *output_file = fopen(output_filepath, "wb");

    unsigned char buf[BUF_SIZE];
    size_t num_read, i, j;

    while ((num_read = fread(buf, sizeof(unsigned char), BUF_SIZE, input_file)) > 0) {
        for (i = 0; i < num_read; ++i) {
            buf[i] ^= key[i % KEY_LENGTH];
        }
        fwrite(buf, sizeof(unsigned char), num_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    unsigned char key[KEY_LENGTH];
    srand((unsigned int) time(NULL));

    printf("Generating random key...");
    fflush(stdout);
    for (size_t i = 0; i < KEY_LENGTH; ++i) {
        key[i] = (unsigned char) (rand() % 256);
    }
    printf("done.\n");

    char *input_filepath = "input.txt";
    char *output_filepath = "encrypted.txt";

    printf("Encrypting file '%s' with key:\n", input_filepath);
    for (size_t i = 0; i < KEY_LENGTH; ++i) {
        printf("%02x ", key[i]);
    }
    printf("\n");

    encrypt(input_filepath, output_filepath, key);

    printf("Encryption complete! Encrypted file written to '%s'\n", output_filepath);
    return 0;
}
//FormAI DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void encrypt(FILE* fp_in, FILE* fp_out, const char* key) {
    char buffer[MAX_BUFFER_SIZE];
    int key_idx = 0;
    size_t n_read;

    while ((n_read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, fp_in)) > 0) {
        for (size_t i = 0; i < n_read; i++) {
            buffer[i] ^= key[key_idx++];
            key_idx %= strlen(key);
        }
        fwrite(buffer, sizeof(char), n_read, fp_out);
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE* fp_in = fopen(argv[1], "rb");
    if (!fp_in) {
        perror("Unable to open input file");
        return 1;
    }

    FILE* fp_out = fopen(argv[2], "wb");
    if (!fp_out) {
        perror("Unable to open output file");
        fclose(fp_in);
        return 1;
    }

    encrypt(fp_in, fp_out, argv[3]);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
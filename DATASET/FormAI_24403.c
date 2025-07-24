//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xA5

/* Encrypts a file using XOR */
void encrypt_file(FILE* in, FILE* out) {
    int c;
    while ((c = fgetc(in)) != EOF) {
        c ^= KEY;
        fputc(c, out);
    }
}

/* Main program */
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* in = fopen(argv[1], "rb");
    if (!in) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE* out = fopen(argv[2], "wb");
    if (!out) {
        printf("Error opening output file: %s\n", argv[2]);
        fclose(in);
        return 1;
    }

    encrypt_file(in, out);

    fclose(in);
    fclose(out);
    return 0;
}
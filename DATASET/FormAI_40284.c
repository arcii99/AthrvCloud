//FormAI DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

/* Custom compression algorithm: shift each character by 2 positions */
void futuristic_compress(unsigned char* buffer, size_t size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = buffer[i] + 2;
    }
}

/* Custom decompression algorithm: shift each character by -2 positions */
void futuristic_decompress(unsigned char* buffer, size_t size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = buffer[i] - 2;
    }
}

int main() {
    FILE* fp_in, * fp_out;
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read;

    /* Open input and output files */
    fp_in = fopen("input.txt", "rb");
    fp_out = fopen("output.bin", "wb");

    /* Compress the input file */
    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp_in)) > 0) {
        futuristic_compress(buffer, bytes_read);
        fwrite(buffer, 1, bytes_read, fp_out);
    }

    /* Close input and output files */
    fclose(fp_in);
    fclose(fp_out);

    /* Open compressed file and output file */
    fp_in = fopen("output.bin", "rb");
    fp_out = fopen("output.txt", "wb");

    /* Decompress the compressed file */
    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp_in)) > 0) {
        futuristic_decompress(buffer, bytes_read);
        fwrite(buffer, 1, bytes_read, fp_out);
    }

    /* Close compressed file and output file */
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
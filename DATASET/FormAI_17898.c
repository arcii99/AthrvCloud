//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define WATERMARK_SIZE 32

/* Surreal digital watermarking algorithm */

int main(int argc, char *argv[]) {
    FILE *infile, *outfile;
    char wm[WATERMARK_SIZE] = "The sky is not what it seems";
    char buffer[MAX_SIZE];
    int i, j = 0, buffer_size, wm_size = strlen(wm);

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    infile = fopen(argv[1], "rb");
    if (!infile) {
        printf("Error: Failed to open file %s\n", argv[1]);
        exit(1);
    }

    outfile = fopen(argv[2], "wb");
    if (!outfile) {
        printf("Error: Failed to open file %s\n", argv[2]);
        exit(1);
    }

    while ((buffer_size = fread(buffer, 1, MAX_SIZE, infile)) != 0) {
        for (i = 0; i < buffer_size && j < wm_size; ++i, ++j) {
            buffer[i] ^= wm[j];
        }

        fwrite(buffer, 1, buffer_size, outfile);

        if (j >= wm_size) {
            j = 0;
        }
    }

    printf("Surrealist watermarking complete!\n");

    fclose(infile);
    fclose(outfile);

    return 0;
}
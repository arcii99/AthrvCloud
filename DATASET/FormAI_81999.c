//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define WATERMARK "This is a watermark"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    if (fin == NULL) {
        printf("Unable to open input file\n");
        return 1;
    }

    FILE *fout = fopen(argv[2], "wb");
    if (fout == NULL) {
        printf("Unable to open output file\n");
        return 1;
    }

    // Read the image data
    size_t size;
    fseek(fin, 0, SEEK_END);
    size = ftell(fin);
    rewind(fin);
    unsigned char *data = (unsigned char*)malloc(size);
    fread(data, sizeof(unsigned char), size, fin);

    // Embed the watermark
    const unsigned watermark_size = sizeof(WATERMARK);
    unsigned i;
    const unsigned char *watermark_bytes = (const unsigned char*)WATERMARK;
    unsigned char *dst = data;
    for (i = 0; i < watermark_size; i++) {
        *dst++ |= (*watermark_bytes >> (7 - (i & 7))) & 1;
    }

    // Write the output to the file
    fwrite(data, sizeof(unsigned char), size, fout);

    free(data);
    fclose(fin);
    fclose(fout);

    return 0;
}
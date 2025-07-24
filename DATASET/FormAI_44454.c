//FormAI DATASET v1.0 Category: Image compression ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define our compression factor
#define COMPRESSION_FACTOR 0.5

int main() {
    // Load image data from file (in this case, a 1024x1024 grayscale image)
    FILE* infile = fopen("image.bin", "rb");
    unsigned char* data = (unsigned char*)malloc(1024 * 1024 * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), 1024 * 1024, infile);
    fclose(infile);

    // Apply compression to image data
    int compressed_size = 1024*1024*COMPRESSION_FACTOR;
    unsigned char* compressed_data = (unsigned char*)malloc(compressed_size * sizeof(unsigned char));
    for (int i = 0; i < compressed_size; i++) {
        compressed_data[i] = data[i*2]; // Skip every other pixel to compress image
    }

    // Output compressed image data to file
    FILE* outfile = fopen("compressed_image.bin", "wb");
    fwrite(compressed_data, sizeof(unsigned char), compressed_size, outfile);
    fclose(outfile);

    // Calculate compression ratio and output result
    int original_size = 1024*1024;
    int compressed_ratio = round((original_size - compressed_size) / (float) original_size * 100);
    printf("Image compressed by %d%%\n", compressed_ratio);

    // Free memory used by image data
    free(data);
    free(compressed_data);

    return 0;
}
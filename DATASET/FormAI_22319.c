//FormAI DATASET v1.0 Category: Image compression ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 256
#define WIDTH 256

int main(void) {
    FILE *in_file, *out_file;
    unsigned char image[HEIGHT][WIDTH], compressed_image[HEIGHT/2][WIDTH/2];
    int i, j, k, l, sum;
    char in_filename[] = "image.raw";
    char out_filename[] = "compressed_image.raw";

    in_file = fopen(in_filename, "rb");
    if (in_file == NULL) {
        printf("Error: Failed to open %s\n", in_filename);
        exit(1);
    }

    out_file = fopen(out_filename, "wb");
    if (out_file == NULL) {
        printf("Error: Failed to open %s\n", out_filename);
        exit(1);
    }

    // Read in image
    fread(image, sizeof(unsigned char), HEIGHT*WIDTH, in_file);

    // Compress image
    for (i = 0, k = 0; i < HEIGHT; i += 2, k++) {
        for (j = 0, l = 0; j < WIDTH; j += 2, l++) {
            sum = image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1];
            compressed_image[k][l] = sum / 4;
        }
    }

    // Write compressed image
    fwrite(compressed_image, sizeof(unsigned char), (HEIGHT/2)*(WIDTH/2), out_file);

    // Close files
    fclose(in_file);
    fclose(out_file);

    printf("Image compression complete!\n");

    return 0;
}
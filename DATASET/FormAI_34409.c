//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

void flip_horizontal(unsigned char* image) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH/2; j++) {
            temp = image[i * WIDTH + j];
            image[i * WIDTH + j] = image[i * WIDTH + (WIDTH - j - 1)];
            image[i * WIDTH + (WIDTH - j - 1)] = temp;
        }
    }
}

int main(int argc, char* argv[]) {
    FILE* input_fp;
    FILE* output_fp;
    char* input_file = "input.raw";
    char* output_file = "output.raw";
    unsigned char image[WIDTH * HEIGHT];

    /* Reading input file */
    input_fp = fopen(input_file, "rb");
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, input_fp);
    fclose(input_fp);

    /* Flipping horizontally */
    flip_horizontal(image);

    /* Writing output file */
    output_fp = fopen(output_file, "wb");
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, output_fp);
    fclose(output_fp);

    return 0;
}
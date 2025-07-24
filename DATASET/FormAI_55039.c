//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WIDTH_RATIO 0.5 // adjust the width to height ratio of ASCII art
#define MAX_PIXEL_VALUE 255 // the maximum pixel value in the image
#define MAX_ASCII_VALUE 255 // the maximum ASCII character value

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_image = argv[1];
    FILE *fp_in = fopen(input_image, "rb");

    if (!fp_in) {
        fprintf(stderr, "Error: could not open image file\n");
        exit(EXIT_FAILURE);
    }

    unsigned char header[54];

    // read the image header
    if (fread(header, sizeof(char), 54, fp_in) != 54) {
        fprintf(stderr, "Error: invalid image file\n");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    // check if the image is a BMP
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a BMP image\n");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    // get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // calculate the padding of the image rows
    int padding = (4 - (width * sizeof(unsigned char)) % 4) % 4;

    // allocate memory for the image pixels
    unsigned char *pixels = malloc(width * height * sizeof(unsigned char));

    if (!pixels) {
        fprintf(stderr, "Error: memory allocation failed\n");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    // read the image pixels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&pixels[i * width + j], sizeof(unsigned char), 1, fp_in);
        }

        fseek(fp_in, padding, SEEK_CUR);
    }

    fclose(fp_in);

    // allocate memory for the ASCII art
    char *ascii_art = malloc(width * height * sizeof(char));

    if (!ascii_art) {
        fprintf(stderr, "Error: memory allocation failed\n");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    // convert the image pixels to ASCII art characters
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value = pixels[i * width + j];
            int ascii_value = pixel_value * MAX_ASCII_VALUE / MAX_PIXEL_VALUE;

            if (isprint(ascii_value)) {
                ascii_art[i * width + j] = (char)ascii_value;
            } else {
                ascii_art[i * width + j] = ' ';
            }
        }
    }

    free(pixels);

    // adjust the width of the ASCII art
    int new_width = (int)(WIDTH_RATIO * width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < new_width; j++) {
            printf("%c", ascii_art[i * width + j]);
        }

        printf("\n");
    }

    free(ascii_art);

    return EXIT_SUCCESS;
}
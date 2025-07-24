//FormAI DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pixel {
    unsigned char r, g, b; // RGB values of the pixel
} Pixel;

int main(int argc, char **argv) {
    if(argc != 4) {
        fprintf(stderr, "usage: %s <input file> <output file> <operation>\n", argv[0]);
        exit(1);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *operation = argv[3];

    FILE *input = fopen(input_file, "rb");
    if(!input) {
        fprintf(stderr, "failed to open %s\n", input_file);
        exit(1);
    }

    FILE *output = fopen(output_file, "wb");
    if(!output) {
        fprintf(stderr, "failed to create %s\n", output_file);
        exit(1);
    }

    // Read the file header
    char header[54];
    fread(header, sizeof(char), 54, input);

    // Write the header to the output file
    fwrite(header, sizeof(char), 54, output);

    int width = *(int*)(header + 18); // Read the width from the header
    int height = *(int*)(header + 22); // Read the height from the header

    // Allocate memory for the pixel buffer
    Pixel *pixels = (Pixel*)malloc(sizeof(Pixel)*width*height);

    // Read the pixel data from the input file
    fread(pixels, sizeof(Pixel), width*height, input);

    if(strcmp(operation, "invert") == 0) {
        // Invert the colors of the image
        for(int i = 0; i < width*height; i++) {
            pixels[i].r = 255 - pixels[i].r;
            pixels[i].g = 255 - pixels[i].g;
            pixels[i].b = 255 - pixels[i].b;
        }
    } else if(strcmp(operation, "grayscale") == 0) {
        // Convert the image to grayscale
        for(int i = 0; i < width*height; i++) {
            unsigned char gray = 0.3*pixels[i].r + 0.59*pixels[i].g + 0.11*pixels[i].b;
            pixels[i].r = gray;
            pixels[i].g = gray;
            pixels[i].b = gray;
        }
    } else if(strcmp(operation, "sepia") == 0) {
        // Convert the image to sepia
        for(int i = 0; i < width*height; i++) {
            unsigned char gray = 0.3*pixels[i].r + 0.59*pixels[i].g + 0.11*pixels[i].b;
            pixels[i].r = gray + 40;
            pixels[i].g = gray + 20;
            pixels[i].b = gray;
        }
    } else {
        fprintf(stderr, "unknown operation: %s\n", operation);
        exit(1);
    }

    // Write the modified pixel data to the output file
    fwrite(pixels, sizeof(Pixel), width*height, output);

    // Clean up
    fclose(input);
    fclose(output);
    free(pixels);

    return 0;
}
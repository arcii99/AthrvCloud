//FormAI DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size

typedef struct {
    unsigned char r, g, b; // RGB color values of a pixel
} Pixel;

int main(int argc, char *argv[]) {
    char input_file[100] = "", output_file[100] = "";
    char operation[10] = "";
    int width = 0, height = 0, max_val = 0;
    Pixel *pixels = NULL;

    // Parse command line arguments
    if (argc == 5) {
        strcpy(input_file, argv[1]);
        strcpy(output_file, argv[2]);
        strcpy(operation, argv[3]);
    } else {
        printf("Usage: %s INPUT_FILE OUTPUT_FILE OPERATION\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *in_fp = fopen(input_file, "rb");
    if (in_fp == NULL) {
        printf("Error: could not open input file '%s'\n", input_file);
        return 1;
    }

    // Read P6 header
    char magic_number[2];
    fscanf(in_fp, "%c%c\n", &magic_number[0], &magic_number[1]);
    if (magic_number[0] != 'P' || magic_number[1] != '6') {
        printf("Error: input file '%s' is not a P6 PPM image file\n", input_file);
        return 1;
    }
    fscanf(in_fp, "%d %d\n", &width, &height);
    fscanf(in_fp, "%d\n", &max_val);
    if (max_val != 255) {
        printf("Error: input file '%s' has an unsupported maximum value of %d\n", input_file, max_val);
        return 1;
    }

    // Allocate memory for pixels
    pixels = (Pixel *) malloc(width * height * sizeof(Pixel));
    if (pixels == NULL) {
        printf("Error: could not allocate memory for pixels\n");
        return 1;
    }

    // Read pixel data
    int num_pixels = width * height;
    int num_pixels_read = fread(pixels, sizeof(Pixel), num_pixels, in_fp);
    if (num_pixels_read != num_pixels) {
        printf("Error: could not read pixel data from input file '%s'\n", input_file);
        return 1;
    }

    // Close input file
    fclose(in_fp);

    // Apply image processing operation
    if (strcmp(operation, "invert") == 0) {
        // Invert the colors of each pixel
        for (int i = 0; i < num_pixels; i++) {
            pixels[i].r = 255 - pixels[i].r;
            pixels[i].g = 255 - pixels[i].g;
            pixels[i].b = 255 - pixels[i].b;
        }
    } else if (strcmp(operation, "grayscale") == 0) {
        // Convert each pixel to grayscale
        for (int i = 0; i < num_pixels; i++) {
            unsigned char gray = (unsigned char) (0.299 * pixels[i].r + 0.587 * pixels[i].g + 0.114 * pixels[i].b);
            pixels[i].r = gray;
            pixels[i].g = gray;
            pixels[i].b = gray;
        }
    } else {
        printf("Error: unsupported image processing operation '%s'\n", operation);
        return 1;
    }

    // Open output file
    FILE *out_fp = fopen(output_file, "wb");
    if (out_fp == NULL) {
        printf("Error: could not open output file '%s'\n", output_file);
        return 1;
    }

    // Write P6 header
    fprintf(out_fp, "P6\n");
    fprintf(out_fp, "%d %d\n", width, height);
    fprintf(out_fp, "255\n");

    // Write pixel data
    int num_pixels_written = fwrite(pixels, sizeof(Pixel), num_pixels, out_fp);
    if (num_pixels_written != num_pixels) {
        printf("Error: could not write pixel data to output file '%s'\n", output_file);
        return 1;
    }

    // Close output file
    fclose(out_fp);

    // Free memory
    free(pixels);

    return 0;
}
//FormAI DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <output_image> <operation>\n", argv[0]);
        printf("Available operations: invert, grayscale, sepia\n");
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *operation = argv[3];

    // Open input file
    FILE *input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: could not open input file %s\n", input_file);
        return 1;
    }

    // Read header
    unsigned char header[HEADER_SIZE];
    if (fread(&header, sizeof(char), HEADER_SIZE, input_fp) != HEADER_SIZE) {
        printf("Error: invalid input file format\n");
        fclose(input_fp);
        return 1;
    }

    // Check if the file is a bitmap
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: not a bitmap file\n");
        fclose(input_fp);
        return 1;
    }

    // Read image size
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate padding
    int padding_size = (4 - (width * 3) % 4) % 4;

    // Allocate memory for the pixel data
    unsigned char *pixel_data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);

    // Read pixel data
    if (fread(pixel_data, sizeof(unsigned char), width * height * 3, input_fp) != width * height * 3) {
        printf("Error: invalid input file format\n");
        free(pixel_data);
        fclose(input_fp);
        return 1;
    }

    // Apply operation to pixel data
    if (strcmp(operation, "invert") == 0) {
        for (int i = 0; i < width * height * 3; i++) {
            pixel_data[i] = 255 - pixel_data[i];
        }
    } else if (strcmp(operation, "grayscale") == 0) {
        for (int i = 0; i < width * height * 3; i+=3) {
            unsigned char r = pixel_data[i];
            unsigned char g = pixel_data[i+1];
            unsigned char b = pixel_data[i+2];
            unsigned char gray = 0.21 * r + 0.72 * g + 0.07 * b;
            pixel_data[i] = gray;
            pixel_data[i+1] = gray;
            pixel_data[i+2] = gray;
        }
    } else if (strcmp(operation, "sepia") == 0) {
        for (int i = 0; i < width * height * 3; i+=3) {
            unsigned char r = pixel_data[i];
            unsigned char g = pixel_data[i+1];
            unsigned char b = pixel_data[i+2];
            unsigned char new_r = 0.393 * r + 0.769 * g + 0.189 * b;
            unsigned char new_g = 0.349 * r + 0.686 * g + 0.168 * b;
            unsigned char new_b = 0.272 * r + 0.534 * g + 0.131 * b;
            pixel_data[i] = new_r > 255 ? 255 : new_r;
            pixel_data[i+1] = new_g > 255 ? 255 : new_g;
            pixel_data[i+2] = new_b > 255 ? 255 : new_b;
        }
    } else {
        printf("Error: invalid operation %s\n", operation);
        free(pixel_data);
        fclose(input_fp);
        return 1;
    }

    // Open output file
    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: could not create output file %s\n", output_file);
        free(pixel_data);
        fclose(input_fp);
        return 1;
    }

    // Write header
    if (fwrite(&header, sizeof(unsigned char), HEADER_SIZE, output_fp) != HEADER_SIZE) {
        printf("Error: could not write output file\n");
        free(pixel_data);
        fclose(input_fp);
        fclose(output_fp);
        return 1;
    }

    // Write pixel data
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            fwrite(&pixel_data[(y * width + x) * 3], sizeof(unsigned char), 3, output_fp);
        }
        if (padding_size > 0) {
            unsigned char padding[3] = {0};
            fwrite(padding, sizeof(unsigned char), padding_size, output_fp);
        }
    }

    // Close files and free memory
    free(pixel_data);
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}
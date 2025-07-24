//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BMP_HEADER_SIZE 54

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input.bmp output.bmp\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open input file for reading
    FILE *in_file = fopen(argv[1], "rb");
    if (!in_file) {
        printf("Error: cannot open input file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Open output file for writing
    FILE *out_file = fopen(argv[2], "wb");
    if (!out_file) {
        printf("Error: cannot open output file %s\n", argv[2]);
        fclose(in_file);
        return EXIT_FAILURE;
    }

    // Read BMP header
    uint8_t header[BMP_HEADER_SIZE];
    if (fread(header, sizeof(uint8_t), BMP_HEADER_SIZE, in_file) != BMP_HEADER_SIZE) {
        printf("Error: invalid BMP header\n");
        fclose(in_file);
        fclose(out_file);
        return EXIT_FAILURE;
    }

    // Check if file is BMP format
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: file format is not BMP\n");
        fclose(in_file);
        fclose(out_file);
        return EXIT_FAILURE;
    }

    // Read image width and height from BMP header
    uint32_t width = *(uint32_t *)(&header[18]);
    uint32_t height = *(uint32_t *)(&header[22]);

    // Find image data offset in BMP header
    uint32_t data_offset = *(uint32_t *)(&header[10]);

    // Compute image size in bytes
    uint32_t image_size = height * ((width * 3 + 3) & ~3);

    // Allocate memory for image data
    uint8_t *data = malloc(image_size);
    if (!data) {
        printf("Error: out of memory\n");
        fclose(in_file);
        fclose(out_file);
        return EXIT_FAILURE;
    }

    // Read image data
    if (fread(data, sizeof(uint8_t), image_size, in_file) != image_size) {
        printf("Error: invalid image data\n");
        fclose(in_file);
        fclose(out_file);
        free(data);
        return EXIT_FAILURE;
    }

    // Close input file
    fclose(in_file);

    // Flip image vertically
    uint32_t row_size = width * 3;
    uint8_t *tmp_row = malloc(row_size);
    if (!tmp_row) {
        printf("Error: out of memory\n");
        fclose(out_file);
        free(data);
        return EXIT_FAILURE;
    }

    for (uint32_t i = 0; i < height / 2; i++) {
        uint8_t *row1 = &data[i * row_size];
        uint8_t *row2 = &data[(height - 1 - i) * row_size];
        memcpy(tmp_row, row1, row_size);
        memcpy(row1, row2, row_size);
        memcpy(row2, tmp_row, row_size);
    }

    // Free temporary memory
    free(tmp_row);

    // Change brightness and contrast
    const float brightness = 50.0f;
    const float contrast = 1.5f;

    for (uint32_t i = 0; i < image_size; i += 3) {
        uint8_t *pixel = &data[i];
        for (int j = 0; j < 3; j++) {
            int value = (int)pixel[j] + brightness;
            value = (int)(value * contrast + 0.5f);
            pixel[j] = (uint8_t)clamp(value, 0, 255);
        }
    }

    // Write BMP header and image data to output file
    if (fwrite(header, sizeof(uint8_t), BMP_HEADER_SIZE, out_file) != BMP_HEADER_SIZE ||
        fwrite(data, sizeof(uint8_t), image_size, out_file) != image_size) {
        printf("Error: cannot write to output file %s\n", argv[2]);
        fclose(out_file);
        free(data);
        return EXIT_FAILURE;
    }

    // Close output file
    fclose(out_file);

    // Free memory
    free(data);

    return EXIT_SUCCESS;
}

int clamp(int value, int min_value, int max_value) {
    if (value < min_value) value = min_value;
    if (value > max_value) value = max_value;
    return value;
}
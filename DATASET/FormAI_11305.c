//FormAI DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * C Image Editor
 *
 * This program modifies an image file by applying basic image processing operations such as
 * grayscale, brightness, contrast, and inversion.
 *
 * The program supports BMP file format only.
 *
 * Usage: cimageeditor inputfile.bmp outputfile.bmp operation [option]
 *
 * Supported operations:
 * - grayscale: Converts the image to a grayscale image.
 * - brightness: Adjusts the brightness of the image by a given amount.
 * - contrast: Adjusts the contrast of the image by a given amount.
 * - inversion: Inverts the colors of the image.
 *
 * Options:
 * - For grayscale operation, no options are available.
 * - For brightness and contrast operations, the option is a number from -255 to 255, representing the amount to adjust by.
 * - For inversion operation, no options are available.
 */

typedef struct __attribute__((__packed__)) {
    char signature[2];
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct __attribute__((__packed__)) {
    unsigned int header_size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression;
    unsigned int image_size;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    unsigned int colors_used;
    unsigned int important_colors;
} BMPInfoHeader;

typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} RGBPixel;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Not enough arguments.\nUsage: %s inputfile.bmp outputfile.bmp operation [option]\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char *operation = argv[3];
    int option = 0;

    if (argc == 5) {
        option = atoi(argv[4]);
    }

    // Open input file
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Cannot open input file %s\n", input_filename);
        return 1;
    }

    // Read BMP header
    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, input_file);

    if (header.signature[0] != 'B' || header.signature[1] != 'M') {
        printf("Error: %s is not a BMP file.\n", input_filename);
        return 1;
    }

    // Read BMP info header
    BMPInfoHeader info_header;
    fread(&info_header, sizeof(BMPInfoHeader), 1, input_file);

    if (info_header.bits_per_pixel != 24 || info_header.compression) {
        printf("Error: Unsupported BMP format.\n");
        return 1;
    }

    // Compute row padding for input file
    int row_padding = (4 - (info_header.width * sizeof(RGBPixel)) % 4) % 4;

    // Allocate memory for image data
    RGBPixel *image_data = malloc(info_header.width * info_header.height * sizeof(RGBPixel));

    // Read image data
    int i, j;
    for (i = 0; i < info_header.height; i++) {
        for (j = 0; j < info_header.width; j++) {
            RGBPixel pixel;
            fread(&pixel, sizeof(RGBPixel), 1, input_file);
            image_data[i * info_header.width + j] = pixel;
        }
        fseek(input_file, row_padding, SEEK_CUR);
    }

    fclose(input_file);

    // Apply image processing operation
    if (strcmp(operation, "grayscale") == 0) {
        for (i = 0; i < info_header.height; i++) {
            for (j = 0; j < info_header.width; j++) {
                RGBPixel pixel = image_data[i * info_header.width + j];
                unsigned char gray = 0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b;
                pixel.r = gray;
                pixel.g = gray;
                pixel.b = gray;
                image_data[i * info_header.width + j] = pixel;
            }
        }
    } else if (strcmp(operation, "brightness") == 0) {
        for (i = 0; i < info_header.height; i++) {
            for (j = 0; j < info_header.width; j++) {
                RGBPixel pixel = image_data[i * info_header.width + j];
                pixel.r = (pixel.r + option) > 255 ? 255 : (pixel.r + option);
                pixel.g = (pixel.g + option) > 255 ? 255 : (pixel.g + option);
                pixel.b = (pixel.b + option) > 255 ? 255 : (pixel.b + option);
                image_data[i * info_header.width + j] = pixel;
            }
        }
    } else if (strcmp(operation, "contrast") == 0) {
        float factor = (259.0 * (option + 255)) / (255.0 * (259 - option));
        for (i = 0; i < info_header.height; i++) {
            for (j = 0; j < info_header.width; j++) {
                RGBPixel pixel = image_data[i * info_header.width + j];
                pixel.r = factor * (pixel.r - 128) + 128;
                pixel.g = factor * (pixel.g - 128) + 128;
                pixel.b = factor * (pixel.b - 128) + 128;
                image_data[i * info_header.width + j] = pixel;
            }
        }
    } else if (strcmp(operation, "inversion") == 0) {
        for (i = 0; i < info_header.height; i++) {
            for (j = 0; j < info_header.width; j++) {
                RGBPixel pixel = image_data[i * info_header.width + j];
                pixel.r = 255 - pixel.r;
                pixel.g = 255 - pixel.g;
                pixel.b = 255 - pixel.b;
                image_data[i * info_header.width + j] = pixel;
            }
        }
    } else {
        printf("Error: Invalid operation.\n");
        return 1;
    }

    // Write modified image to output file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Cannot open output file %s\n", output_filename);
        return 1;
    }

    // Write BMP header
    fwrite(&header, sizeof(BMPHeader), 1, output_file);

    // Write BMP info header
    fwrite(&info_header, sizeof(BMPInfoHeader), 1, output_file);

    // Compute row padding for output file
    row_padding = (4 - (info_header.width * sizeof(RGBPixel)) % 4) % 4;

    // Write image data
    for (i = 0; i < info_header.height; i++) {
        for (j = 0; j < info_header.width; j++) {
            fwrite(&image_data[i * info_header.width + j], sizeof(RGBPixel), 1, output_file);
        }
        // Pad row to a multiple of 4 bytes
        if (row_padding) {
            fwrite("\0\0\0", row_padding, 1, output_file);
        }
    }

    fclose(output_file);

    // Free memory
    free(image_data);

    return 0;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

/* Converts an RGB color to a grayscale intensity  */
int grayscale(int red, int green, int blue) {
    return (red + green + blue) / 3;
}

void image_to_ascii(char filename[]) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char ascii_chars[] = " .,:;i1tfLCG08@";
    int num_chars = strlen(ascii_chars);

    // Read header (first 54 bytes of file)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Extract image dimensions and data from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int offset = *(int*)&header[10];
    int bits_per_pixel = *(int*)&header[28];

    // Only 24-bit RGB color images supported
    if (bits_per_pixel != 24) {
        printf("Unsupported color depth %d\n", bits_per_pixel);
        exit(EXIT_FAILURE);
    }

    // Calculate padding stride for each scanline
    int padding_size = (4 - (width * 3) % 4) % 4;

    // Allocate memory for image RGB data and ASCII buffer
    unsigned char img_data[height][width][3];
    char ascii_buffer[MAX_HEIGHT][MAX_WIDTH];

    // Read image data into buffer
    fseek(fp, offset, SEEK_SET);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, fp);
            img_data[i][j][0] = pixel[2]; // switch from RGB to BGR format
            img_data[i][j][1] = pixel[1];
            img_data[i][j][2] = pixel[0];
        }
        fseek(fp, padding_size, SEEK_CUR);
    }

    // Convert image data to ASCII art and print to terminal
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int intensity = grayscale(img_data[i][j][0], img_data[i][j][1], img_data[i][j][2]);
            int char_index = (intensity * (num_chars - 1)) / 255;
            ascii_buffer[i][j] = ascii_chars[char_index];
        }
        printf("%s\n", ascii_buffer[i]);
    }

    fclose(fp);
}

int main() {
    image_to_ascii("image.bmp");
    return 0;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define ORIG_WIDTH 160
#define ORIG_HEIGHT 80
#define SCALE_FACTOR 4

void convert_to_ascii(char* pixel_data, int width, int height) {
    int i, j;
    for (i = 0; i < height; i += SCALE_FACTOR) {
        for (j = 0; j < width; j += SCALE_FACTOR) {
            int index = ((i * width) + j) * 3;
            int r = pixel_data[index];
            int g = pixel_data[index + 1];
            int b = pixel_data[index + 2];
            int luminance = (int)(0.2126 * r + 0.7152 * g + 0.0722 * b);
            char ascii_char = ' ';

            if (luminance >= 230) {
                ascii_char = ' ';
            } else if (luminance >= 200) {
                ascii_char = '.';
            } else if (luminance >= 180) {
                ascii_char = ':';
            } else if (luminance >= 160) {
                ascii_char = '*';
            } else if (luminance >= 130) {
                ascii_char = '=';
            } else if (luminance >= 100) {
                ascii_char = '+';
            } else if (luminance >= 70) {
                ascii_char = '#';
            } else if (luminance >= 50) {
                ascii_char = '%';
            } else if (luminance >= 30) {
                ascii_char = '@';
            } else {
                ascii_char = '&';
            }

            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    FILE* image_file = fopen("image.bmp", "rb");
    if (!image_file) {
        fprintf(stderr, "Could not open the file.");
        exit(1);
    }

    // Skip the BMP file header
    fseek(image_file, 54, SEEK_SET);

    char pixel_data[ORIG_WIDTH * ORIG_HEIGHT * 3];
    fread(pixel_data, 3, ORIG_WIDTH * ORIG_HEIGHT, image_file);

    convert_to_ascii(pixel_data, ORIG_WIDTH, ORIG_HEIGHT);

    fclose(image_file);
    return 0;
}
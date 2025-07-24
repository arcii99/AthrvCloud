//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The image dimensions
#define WIDTH 80
#define HEIGHT 60

// The character set used for ASCII art
static const char charset[] = " .,:;ox%#@";

// Utility function to convert an RGB color value to grayscale
int to_grayscale(int r, int g, int b)
{
    return ((r * 0.3) + (g * 0.59) + (b * 0.11)) / 255.0 * 10;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *image = fopen(argv[1], "r");

    if (!image) {
        printf("Failed to open image file\n");
        return EXIT_FAILURE;
    }

    char buffer[WIDTH + 1];
    int pixel_count = WIDTH * HEIGHT;

    // Read and convert image pixels to grayscale ASCII characters
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            unsigned char r, g, b;
            fread(&r, 1, 1, image);
            fread(&g, 1, 1, image);
            fread(&b, 1, 1, image);
            int gray = to_grayscale(r, g, b);
            buffer[j] = charset[gray];
        }
        buffer[WIDTH] = '\0';
        printf("%s\n", buffer);
    }

    fclose(image);

    return EXIT_SUCCESS;
}
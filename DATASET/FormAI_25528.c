//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>

#define WIDTH 100
#define HEIGHT 100

// Function to convert a pixel value to ASCII character
char pixelToChar(int p) {
    const char *chars = " .:-=+*#%@";
    int index = (int)(10 * p / 255.0);
    return chars[index];
}

int main() {
    printf("Image to ASCII Art Converter\n\n");

    // Load image from file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Check image size
    if (width != WIDTH || height != HEIGHT) {
        printf("Error: image must be %dx%d.\n", WIDTH, HEIGHT);
        fclose(fp);
        return 1;
    }

    // Read image data
    unsigned char data[WIDTH * HEIGHT * 3];
    fread(data, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Convert image data to ASCII art
    char ascii[WIDTH * HEIGHT];
    int index = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate pixel value
            int r = data[(y * WIDTH + x) * 3 + 2];
            int g = data[(y * WIDTH + x) * 3 + 1];
            int b = data[(y * WIDTH + x) * 3];
            int gray = (r + g + b) / 3;

            // Convert pixel value to ASCII character
            ascii[index++] = pixelToChar(gray);
        }
        ascii[index++] = '\n';  // Add newline character at end of row
    }
    ascii[index] = '\0';  // Add null character at end of string

    // Print ASCII art to console
    printf("%s", ascii);

    return 0;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>

// Define the width and height of the image
#define WIDTH 100
#define HEIGHT 100

// Define the ASCII characters to be used for different grayscale levels
const char* ASCII_CHARS = " .:-=+*#%@";

// Function to convert a pixel value to an ASCII character
char pixel_to_char(int pixel) {
    // Map the pixel value from the range 0-255 to the range 0-9 for ASCII_CHARS
    int char_index = pixel / 26;
    // Return the corresponding character
    return ASCII_CHARS[char_index];
}

int main() {
    // Define the image buffer
    int image[WIDTH][HEIGHT];
    // Load the image data from a file
    FILE* image_file = fopen("image.data", "rb");
    fread(image, sizeof(int), WIDTH * HEIGHT, image_file);
    fclose(image_file);
    // Iterate over the pixels in the image and convert them to ASCII characters
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            int pixel_value = image[i][j];
            char ascii_char = pixel_to_char(pixel_value);
            // Print the ASCII character
            printf("%c", ascii_char);
        }
        // Print a newline character to move to the next row
        printf("\n");
    }
    return 0;
}
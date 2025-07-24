//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>

// Define constant values for the width and height of the image
#define WIDTH 20
#define HEIGHT 10

// Define the function to convert an image pixel to ASCII character
char pixelToChar(int pixel) {
    // ASCII characters ordered by brightness from dark to light
    char chars[] = {'#', '&', '$', 'x', 'o', ':', ',', '.', ' '};
    // Calculate the index of the character based on the brightness of the pixel
    int index = 9 * pixel / 255;
    // Return the corresponding character
    return chars[index];
}

int main() {
    // Define an example image as a 2D array of integers
    int image[HEIGHT][WIDTH] = {
        {  0,  20,  40,  60,  80, 100, 120, 140, 160, 180, 200, 220, 240, 255, 240, 220, 200, 180, 160, 140 },
        {  0,  16,  32,  48,  64,  80,  96, 112, 128, 144, 160, 176, 192, 208, 224, 208, 192, 176, 160, 144 },
        {  0,  12,  24,  36,  48,  60,  72,  84,  96, 108, 120, 132, 144, 156, 168, 156, 144, 132, 120, 108 },
        {  0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96, 104, 112, 104,  96,  88,  80,  72 },
        {  0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48,  52,  56,  52,  48,  44,  40,  36 },
        {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        { 40,  80, 120, 160, 200, 240, 200, 160, 120,  80,  40,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        { 60, 120, 180, 240, 180, 120,  60,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        { 80, 160, 240, 160,  80,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        {100, 200, 100,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    };

    // Loop over the pixels of the image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert the pixel to an ASCII character
            char c = pixelToChar(image[y][x]);
            // Print the character to the console
            putchar(c);
        }
        // Print a newline character at the end of each row
        putchar('\n');
    }

    // Exit the program with status code 0 to indicate success
    return 0;
}
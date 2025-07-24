//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image details
#define WIDTH 100
#define HEIGHT 50

// ASCII art characters
const char ascii_chars[] = " .,-~:;=!*#$@";

// Math helper functions
double clamp(double val, double min, double max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

int map(int val, int in_min, int in_max, int out_min, int out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Main program
int main() {
    // Load image
    FILE *fp = fopen("image.raw", "rb");
    if (!fp) {
        printf("Error: could not open image file.\n");
        return 1;
    }
    unsigned char image[WIDTH * HEIGHT];
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Convert image to ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get pixel value
            double pixel_val = image[y * WIDTH + x] / 255.0;

            // Map pixel value to ASCII character index
            int char_index = map(pixel_val, 0, 1, 0, strlen(ascii_chars) - 1);

            // Get ASCII character
            char ascii_char = ascii_chars[char_index];

            // Print ASCII character
            printf("%c ", ascii_char);
        }
        printf("\n");
    }

    return 0;
}
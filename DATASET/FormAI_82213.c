//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // set up the size of the pixel art canvas
    const int width = 16;
    const int height = 8;

    // set up the characters used to generate the pixel art
    const char pixels[8] = {' ', '.', ':', '-', '=', '+', '*', '#'};
    const int num_pixels = sizeof(pixels) / sizeof(char);

    // seed the random number generator
    srand(time(NULL));

    // generate the pixel art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // generate a random pixel character
            int pixel_idx = rand() % num_pixels;
            char pixel = pixels[pixel_idx];
            
            // print the pixel character
            printf("%c", pixel);
        }
        // print a newline character to create a new row
        printf("\n");
    }

    return 0;
}
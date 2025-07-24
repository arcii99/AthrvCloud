//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 5
#define PIXEL_SPACE 1
#define ART_HEIGHT 25
#define ART_WIDTH 35

void generatePixelArt(int artHeight, int artWidth) {
    srand(time(NULL)); // initialize random seed

    // loop through each row of pixels
    for (int row = 0; row < artHeight; row++) {
        // loop through each pixel in the row
        for (int col = 0; col < artWidth; col++) {
            // randomly generate a color value as a hex string
            char color[7];
            sprintf(color, "%06X", rand() % 0xFFFFFF);

            // loop through each pixel size
            for (int i = 0; i < PIXEL_SIZE; i++) {
                // print out the pixel color
                printf("\033[48;2;%sm%*c", color, PIXEL_SIZE + PIXEL_SPACE, ' ');
            }
        }

        // print a new line to move to the next row
        printf("\033[0m\n");
    }
}

int main() {
    generatePixelArt(ART_HEIGHT, ART_WIDTH);
    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdlib.h>
#include <stdio.h>

#define CANVAS_SIZE 100
#define PIXEL_SIZE 10

int main(void) {
    // initialize canvas with all white pixels
    int canvas[CANVAS_SIZE][CANVAS_SIZE];
    for(int i = 0; i < CANVAS_SIZE; i++) {
        for(int j = 0; j < CANVAS_SIZE; j++) {
            canvas[i][j] = 255;
        }
    }

    // generate random pixel art
    for(int i = 0; i < CANVAS_SIZE/PIXEL_SIZE; i++) {
        for(int j = 0; j < CANVAS_SIZE/PIXEL_SIZE; j++) {
            // generate random RGB values for the pixel
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;

            // apply the color to each of the 100 pixels in the block
            for(int k = i*PIXEL_SIZE; k < (i+1)*PIXEL_SIZE; k++) {
                for(int l = j*PIXEL_SIZE; l < (j+1)*PIXEL_SIZE; l++) {
                    canvas[k][l] = r;
                    canvas[k][l+1] = g;
                    canvas[k][l+2] = b;
                }
            }
        }
    }

    // print out the resulting pixel art
    for(int i = 0; i < CANVAS_SIZE; i++) {
        for(int j = 0; j < CANVAS_SIZE; j++) {
            printf("%03d ", canvas[i][j]);
        }
        printf("\n");
    }

    return 0;
}
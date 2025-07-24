//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>

#define WIDTH 8 // width of the canvas
#define HEIGHT 8 // height of the canvas

int main() {
    int pixels[WIDTH][HEIGHT] = { // define the canvas with a 2D array
        {0, 0, 0, 0, 0, 0, 0, 0}, // row0
        {0, 1, 1, 0, 0, 1, 1, 0}, // row1
        {0, 1, 1, 0, 0, 1, 1, 0}, // row2
        {0, 0, 0, 0, 0, 0, 0, 0}, // row3
        {0, 1, 0, 0, 0, 0, 1, 0}, // row4
        {0, 0, 1, 1, 1, 1, 0, 0}, // row5
        {0, 0, 0, 0, 0, 0, 0, 0}, // row6
        {0, 0, 0, 0, 0, 0, 0, 0}, // row7
    };

    // print out the canvas as pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixels[i][j] == 1) printf("o"); // if the pixel is colored
            else printf(" "); // if the pixel is not colored
        }
        printf("\n"); // print a new line after each row
    }

    return 0;
}
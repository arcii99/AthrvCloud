//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width = 30; // width of the grid
    int height = 20; // height of the grid
    int pixels[height][width]; // 2D array to hold the pixels

    int i, j; // loop variables
    
    srand(time(NULL)); // seed the random number generator

    // initialize all pixels to 0 (black)
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            pixels[i][j] = 0;
        }
    }

    // randomly set some pixels to 1 (white)
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            if(rand() % 10 == 0) {
                pixels[i][j] = 1;
            }
        }
    }

    // output the pixel art
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            if(pixels[i][j] == 0) {
                printf("  "); // black pixel
            } else {
                printf("**"); // white pixel
            }
        }
        printf("\n");
    }

    return 0;
}
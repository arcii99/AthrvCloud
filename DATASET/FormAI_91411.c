//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random pixel colors
void generatePixel(int *red, int *green, int *blue) {
    int range = 256;
    *red = rand() % range;
    *green = rand() % range;
    *blue = rand() % range;
}

int main() {
    // set the size of the pixel art
    int width = 20;
    int height = 20;
    
    // declare the pixel array
    int pixel[height][width][3];
    
    // seed the random number generator
    srand(time(NULL));
    
    // generate the pixel array
    for (int row=0; row<height; row++) {
        for (int col=0; col<width; col++) {
            generatePixel(&pixel[row][col][0], &pixel[row][col][1], &pixel[row][col][2]);
        }
    }
    
    // print the pixel array as a pixel art
    for (int row=0; row<height; row++) {
        for (int col=0; col<width; col++) {
            printf("\033[48;2;%d;%d;%dm  \033[0m", pixel[row][col][0], pixel[row][col][1], pixel[row][col][2]);
        }
        printf("\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 5

void printPixel(char pixel[PIXEL_SIZE][PIXEL_SIZE]) {
    for(int i=0; i<PIXEL_SIZE; ++i) {
        for(int j=0; j<PIXEL_SIZE; ++j) {
            printf("%c ", pixel[i][j]);
        }
        printf("\n");
    }
}

void generatePixelArt() {
    srand(time(NULL));
    char pixel[PIXEL_SIZE][PIXEL_SIZE];

    // Generate the pixel art with random colors
    for(int i=0; i<PIXEL_SIZE; ++i) {
        for(int j=0; j<PIXEL_SIZE; ++j) {
            int color = rand() % 3;
            if(color == 0) {
                pixel[i][j] = 'R';
            } else if(color == 1) {
                pixel[i][j] = 'G';
            } else {
                pixel[i][j] = 'B';
            }
        }
    }

    // Print the pixel art
    printPixel(pixel);
}

int main() {
    generatePixelArt();
    return 0;
}
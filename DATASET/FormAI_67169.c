//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for screen size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// functions to set and clear pixels
void setPixel(unsigned char screen[SCREEN_WIDTH][SCREEN_HEIGHT/8], int x, int y) {
    screen[x][y/8] |= 1 << (7-(y%8));
}

void clearPixel(unsigned char screen[SCREEN_WIDTH][SCREEN_HEIGHT/8], int x, int y) {
    screen[x][y/8] &= ~(1 << (7-(y%8)));
}

// function to generate random pixel art
void generatePixelArt(unsigned char screen[SCREEN_WIDTH][SCREEN_HEIGHT/8]) {
    int i, j;
    srand(time(NULL)); // seed the random number generator

    // loop through all pixels on the screen
    for(i=0; i<SCREEN_WIDTH; i++) {
        for(j=0; j<SCREEN_HEIGHT; j++) {
            // randomly set or clear each pixel
            if(rand() % 2 == 0) {
                setPixel(screen, i, j);
            }
            else {
                clearPixel(screen, i, j);
            }
        }
    }
}

int main() {
    // initialize screen array
    unsigned char screen[SCREEN_WIDTH][SCREEN_HEIGHT/8] = {0};

    // generate some pixel art
    generatePixelArt(screen);

    // output screen array as hex values
    int i, j;
    for(i=0; i<SCREEN_WIDTH; i++) {
        for(j=0; j<SCREEN_HEIGHT/8; j++) {
            printf("%02x ", screen[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

char pixels[WIDTH][HEIGHT];

void init_pixels() {
    // set all pixels to background color (white)
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            pixels[i][j] = '.';
        }
    }
}

void draw_pixels() {
    for(int j=0; j<HEIGHT; j++) {
        for(int i=0; i<WIDTH; i++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_pixels();

    // generate random pixels
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            if(rand() % 4 == 0) {
                pixels[i][j] = 'X';
            }
        }
    }

    draw_pixels();

    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define PIXELS 256

void printPixel(char pixel[PIXELS][PIXELS]) {
    for (int i=0; i < PIXELS; i++) {
        for (int j=0; j < PIXELS; j++) {
            printf("%c", pixel[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixel[PIXELS][PIXELS];
    srand(time(NULL));

    // Initialize the pixel grid to all white
    for (int i=0; i < PIXELS; i++) {
        for (int j=0; j < PIXELS; j++) {
            pixel[i][j] = 'O';
        }
    }

    // Draw vertical lines of black pixels at random positions
    for (int i=0; i < WIDTH/2; i++) {
        int x = rand() % PIXELS;
        for (int j=0; j < HEIGHT; j++) {
            pixel[x][j] = '#';
        }
    }

    // Draw horizontal lines of black pixels at random positions
    for (int i=0; i < HEIGHT/2; i++) {
        int y = rand() % PIXELS;
        for (int j=0; j < WIDTH; j++) {
            pixel[j][y] = '#';
        }
    }

    // Draw diagonal lines of black pixels at random positions
    for (int i=PIXELS/4; i > 0; i-=2) {
        int x = rand() % (PIXELS-i);
        int y = rand() % (PIXELS-i);
        for (int j=0; j < i; j++) {
            pixel[x+j][y+j] = '#';
        }
    }

    // Draw diagonal lines of black pixels at random positions
    for (int i=PIXELS/4; i > 0; i-=2) {
        int x = rand() % (PIXELS-i);
        int y = rand() % (PIXELS-i);
        for (int j=0; j < i; j++) {
            pixel[PIXELS-x-j-1][y+j] = '#';
        }
    }

    // Print the pixel art to the console
    printPixel(pixel);

    return 0;
}
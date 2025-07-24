//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int pixels[WIDTH][HEIGHT][3];

void fillPixelCanvas() {
    // Initialize each pixel with a default color
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            pixels[i][j][0] = 204; // Red
            pixels[i][j][1] = 204; // Green
            pixels[i][j][2] = 204; // Blue
        }
    }
}

void generatePixelArt() {
    // Randomly generate color values for each pixel
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            pixels[i][j][0] = rand() % 256; // Red
            pixels[i][j][1] = rand() % 256; // Green
            pixels[i][j][2] = rand() % 256; // Blue
        }
    }
}

void printPixelArt() {
    // Print out the pixel art as ASCII art
    printf("\n\n");
    for(int i = 0; i < WIDTH; i++) {
        printf(" ");
        for(int j = 0; j < HEIGHT; j++) {
            // Add some glitchy effects by randomly introducing static-like patterns
            if(rand() % 10 == 5) {
                printf("#");
            } else {
                printf(" ");
            }
            printf("\033[48;2;%d;%d;%dm ", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
            printf("\033[0m");
        }
        printf(" \n");
    }
}

int main() {
    srand(time(NULL));

    fillPixelCanvas();
    generatePixelArt();
    printPixelArt();

    return 0;
}
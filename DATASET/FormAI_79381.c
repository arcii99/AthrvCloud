//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define pixel art dimensions
#define WIDTH 20
#define HEIGHT 10

// Define pixel art symbols
#define PIXEL_CHAR 'X'
#define BLANK_CHAR ' '

// Function to generate random pixel art
void generatePixelArt(char pixelArt[HEIGHT][WIDTH]) {
    int i, j;
    srand(time(NULL));
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            int random = rand() % 2;
            if (random == 0) {
                pixelArt[i][j] = PIXEL_CHAR;
            } else {
                pixelArt[i][j] = BLANK_CHAR;
            }
        }
    }
}

// Function to print the generated pixel art
void printPixelArt(char pixelArt[HEIGHT][WIDTH]) {
    int i, j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char pixelArt[HEIGHT][WIDTH];
    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);
    return 0;
}
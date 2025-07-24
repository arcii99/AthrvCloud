//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define pixel colors
#define BLACK 0
#define WHITE 1

// Define image dimensions
#define WIDTH 10
#define HEIGHT 10

// Define pixel art dimensions
#define PIXEL_ART_WIDTH 5
#define PIXEL_ART_HEIGHT 5

// Define pixel art scale factor
#define SCALE_FACTOR 2

// Define color map for input image
int colorMap[HEIGHT][WIDTH] = {
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 1}
};

// Define pixel art grid
int pixelArt[PIXEL_ART_HEIGHT][PIXEL_ART_WIDTH] = {0};

// Define function to convert input image into pixel art
void generatePixelArt() {
    int i, j, k, l;
    for (i = 0; i < PIXEL_ART_HEIGHT; i++) {
        k = i * SCALE_FACTOR;
        for (j = 0; j < PIXEL_ART_WIDTH; j++) {
            l = j * SCALE_FACTOR;
            pixelArt[i][j] = colorMap[k][l];
        }
    }
}

// Define function to display pixel art
void displayPixelArt() {
    int i, j;
    for (i = 0; i < PIXEL_ART_HEIGHT; i++) {
        for (j = 0; j < PIXEL_ART_WIDTH; j++) {
            printf("%c ", pixelArt[i][j] == BLACK ? '.' : '*');
        }
        printf("\n");
    }
}

int main() {
    generatePixelArt();
    displayPixelArt();
    return 0;
}
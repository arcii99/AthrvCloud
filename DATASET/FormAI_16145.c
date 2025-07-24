//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int width, int height) {
    int pixelGrid[height][width];
    int colorPalette[10] = { 0x000000, 0xFFFFFF, 0xFF0000, 0x00FF00, 0x0000FF, 
                             0xFFFF00, 0xFF00FF, 0x00FFFF, 0xC0C0C0, 0x808080 };
    int i, j;
    srand(time(0));

    // Initialize pixel grid with random colors
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int randomColor = colorPalette[rand() % 10];
            pixelGrid[i][j] = randomColor;
        }
    }

    // Print pixel grid as ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int color = pixelGrid[i][j];
            if (color == 0x000000) {
                printf("  ");
            } else if (color == 0xFFFFFF) {
                printf("##");
            } else if (color == 0xFF0000) {
                printf("r ");
            } else if (color == 0x00FF00) {
                printf("g ");
            } else if (color == 0x0000FF) {
                printf("b ");
            } else if (color == 0xFFFF00) {
                printf("y ");
            } else if (color == 0xFF00FF) {
                printf("m ");
            } else if (color == 0x00FFFF) {
                printf("c ");
            } else if (color == 0xC0C0C0) {
                printf(". ");
            } else if (color == 0x808080) {
                printf(": ");
            }
        }
        printf("\n");
    }
}

int main() {
    generatePixelArt(16, 16);
    return 0;
}
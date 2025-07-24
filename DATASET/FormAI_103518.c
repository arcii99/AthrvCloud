//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random colors
void getColor(int pixel[3]) {
    pixel[0] = rand() % 256;  // Red component
    pixel[1] = rand() % 256;  // Green component
    pixel[2] = rand() % 256;  // Blue component
}

// Function to generate the pixel art
void generatePixelArt(int pixels[64][64][3]) {
    // Generating random pixels
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            getColor(pixels[i][j]);
        }
    }

    // Drawing patterns
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            // Drawing a horizontal pattern
            if (i % 8 == 0) {
                pixels[i][j][0] = 0;
                pixels[i][j][1] = 0;
                pixels[i][j][2] = 0;
            }
            // Drawing a vertical pattern
            if (j % 8 == 0) {
                pixels[i][j][0] = 255;
                pixels[i][j][1] = 255;
                pixels[i][j][2] = 255;
            }
            // Drawing a checkerboard pattern
            if (i % 16 == 0 && j % 16 == 0) {
                pixels[i][j][0] = 255;
                pixels[i][j][1] = 0;
                pixels[i][j][2] = 255;
            }
            if (i % 16 == 8 && j % 16 == 8) {
                pixels[i][j][0] = 255;
                pixels[i][j][1] = 0;
                pixels[i][j][2] = 255;
            }
        }
    }
}

// Function to print the pixel art
void printPixelArt(int pixels[64][64][3]) {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            printf("\033[48;2;%d;%d;%dm  \033[0m", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
        }
        printf("\n");
    }
}

int main() {
    int pixels[64][64][3];
    srand(time(NULL));  // Seeding the random number generator
    generatePixelArt(pixels);
    printPixelArt(pixels);
    return 0;
}
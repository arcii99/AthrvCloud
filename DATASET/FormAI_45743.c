//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define PIXEL_SIZE 10

// Function to generate random pixel colors
int generatePixelColor() {
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    return (r << 16) | (g << 8) | b;
}

// Function to generate random pixel art
void generatePixelArt(int pixelArt[HEIGHT][WIDTH]) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = generatePixelColor();
        }
    }
}

// Function to print the pixel art to the console
void printPixelArt(int pixelArt[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            for (int k = 0; k < PIXEL_SIZE; k++) {
                for (int l = 0; l < PIXEL_SIZE; l++) {
                    printf("\033[48;2;%d;%d;%dm  \033[0m", (pixelArt[i][j] >> 16) & 0xFF, (pixelArt[i][j] >> 8) & 0xFF, pixelArt[i][j] & 0xFF);
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int pixelArt[HEIGHT][WIDTH];
    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);
    return 0;
}
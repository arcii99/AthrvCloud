//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define PIXEL_SIZE 5

void printPixel(char character) {
    for (int i = 0; i < PIXEL_SIZE; i++) {
        printf("%c", character);
    }
}

int main(void) {
    char pixels[WIDTH][HEIGHT];
    srand(time(NULL)); // Seed the random number generator

    // Generate random character pixels
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixels[i][j] = rand() % 256;
        }
    }

    // Print the pixel art
    for (int i = 0; i < WIDTH; i++) {
        for (int h = 0; h < PIXEL_SIZE; h++) { // Horizontal repetition
            for (int j = 0; j < HEIGHT; j++) {
                for (int w = 0; w < PIXEL_SIZE; w++) { // Vertical repetition
                    printPixel(pixels[i][j]);
                }
            }
            printf("\n"); // New line after a row of pixels has been printed
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int width, int height) {
    // Create an array to store the pixel colors
    char pixels[height][width];

    // Initialize the random seed
    srand(time(NULL));

    // Generate random colors for each pixel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int randomColor = rand() % 2;
            if (randomColor == 0) {
                pixels[i][j] = ' ';
            } else {
                pixels[i][j] = '*';
            }
        }
    }

    // Print the pixel art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define the size of the pixel art
    int width = 20;
    int height = 10;

    // Generate and print the pixel art
    generatePixelArt(width, height);

    return 0;
}
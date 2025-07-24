//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generatePixelArt(int width, int height) {
    char pixels[height * width];

    // Seed the random number generator
    srand(time(NULL));

    // Generate pixel values
    for(int i = 0; i < height * width; i++) {
        // Randomly choose a pixel value
        pixels[i] = rand() % 2 == 0 ? '#' : '.';
    }

    // Output pixel art
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            printf("%c", pixels[y * width + x]);
        }
        printf("\n");
    }
}

int main() {
    // Generate 10x10 pixel art
    generatePixelArt(10, 10);

    return 0;
}
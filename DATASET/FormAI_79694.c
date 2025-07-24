//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>

// define the size of the screen
#define WIDTH 80
#define HEIGHT 30

// define the size of the pixel
#define PIXEL_WIDTH 2
#define PIXEL_HEIGHT 1

// pixel art function
void drawPixel(char pixel) {
    for (int i = 0; i < PIXEL_WIDTH; i++) {
        for (int j = 0; j < PIXEL_HEIGHT; j++) {
            printf("%c", pixel);
        }
        printf("\n");
    }
}

// pixel art generator
void generatePixelArt(char *characters, int size) {

    // iterate over every pixel and draw a random character
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int index = rand() % size;
            drawPixel(characters[index]);
        }
        printf("\n");
    }
}

int main() {
    char characters[] = {'*', '+', '-', '_', '|', '#', '@', '!'};
    int size = sizeof(characters) / sizeof(char);

    generatePixelArt(characters, size);

    return 0;
}
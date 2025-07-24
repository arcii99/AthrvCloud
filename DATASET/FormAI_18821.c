//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void drawPixel(int x, int y, char pixel) {
    // Draw a single pixel at position (x, y)
    printf("%c ", pixel);
}

void drawLine(int startX, int endX, int y, char pixel) {
    // Draw a line from (startX, y) to (endX, y)
    int i;
    for (i = startX; i <= endX; i++) {
        drawPixel(i, y, pixel);
    }
}

void generateRandomArt(char pixels[], int numPixels) {
    // Fills the pixels array with random characters
    int i;
    for (i = 0; i < numPixels; i++) {
        pixels[i] = rand() % 2 ? '#' : '*';
    }
}

void drawArt(char pixels[], int width, int height) {
    // Draws the pixels array as a grid of characters
    int x, y, index;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            index = y * width + x;
            drawPixel(x, y, pixels[index]);
        }
        printf("\n");
    }
}

void generatePixelArt() {
    char pixels[WIDTH * HEIGHT];
    generateRandomArt(pixels, WIDTH * HEIGHT);
    drawArt(pixels, WIDTH, HEIGHT);
}

int main() {
    srand(time(NULL));
    generatePixelArt();
    return 0;
}
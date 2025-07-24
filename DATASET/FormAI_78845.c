//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createPixel(char pixel[2]) {
    int r = rand() % 16;
    sprintf(pixel, "%X", r);
}

void generatePixelArt(int width, int height) {
    srand(time(NULL));
    char pixel[2];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            createPixel(pixel);
            printf("\033[48;5;%sm  \033[0m", pixel);
        }
        printf("\n");
    }
}

int main() {
    int width = 32;
    int height = 16;
    generatePixelArt(width, height);
    return 0;
}
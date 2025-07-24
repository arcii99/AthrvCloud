//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

void printPixel(char c) {
    switch (c) {
        case '0':
            printf(" ");
            break;
        case '1':
            printf("#");
            break;
        case '2':
            printf("+");
            break;
        case '3':
            printf("@");
            break;
    }
}

void generatePixelArt(int pixels[WIDTH][HEIGHT]) {
    int x, y;
    char asciiPixels[WIDTH][HEIGHT];
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x  < WIDTH; x++) {
            if (pixels[x][y] < 32) {
                asciiPixels[x][y] = '0';   
            } else if (pixels[x][y] < 64) {
                asciiPixels[x][y] = '1';   
            } else if (pixels[x][y] < 96) {
                asciiPixels[x][y] = '2';   
            } else {
                asciiPixels[x][y] = '3';   
            }
            printPixel(asciiPixels[x][y]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int pixels[WIDTH][HEIGHT];
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            pixels[x][y] = rand() % 128;   
        }
    }
    generatePixelArt(pixels);
    return 0;
}
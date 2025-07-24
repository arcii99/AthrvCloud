//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 20
#define HEIGHT 20

/* Function to generate random color values */
void randomColor(char *colorCode) {
    int i;
    static const char characters[] = "0123456789ABCDEF";
    for (i = 0; i < 6; i++) {
        colorCode[i] = characters[rand() % 16];
    }
}

/* Function to print the pixel art */
void printPixelArt(char pixelArt[HEIGHT][WIDTH][7]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%s ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixelArt[HEIGHT][WIDTH][7];
    srand(time(NULL));
    int i, j;

    /* Generate random color values for each pixel */
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            char colorCode[7];
            randomColor(colorCode);
            sprintf(pixelArt[i][j], "\e[48;2;%s;  ", colorCode);
        }
    }

    printPixelArt(pixelArt);
    return 0;
}
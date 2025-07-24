//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 30

char pixelArt[HEIGHT][WIDTH];
char pixelChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

/* A function to set a pixel in the pixelArt array */
void setPixel(int x, int y, char c) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    pixelArt[y][x] = c;
}

/* A function to print the pixelArt array */
void printPixelArt() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }
}

/* A function to generate a random pixel character */
char getRandomPixelChar() {
    int idx = rand() % 10;
    return pixelChars[idx];
}

/* A function to fill the pixelArt array with random pixel characters */
void fillPixelArt() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char c = getRandomPixelChar();
            setPixel(j, i, c);
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    /* Initialize the pixelArt array with spaces */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = ' ';
        }
    }

    /* Fill the pixelArt array with random pixel characters and print it */
    fillPixelArt();
    printPixelArt();

    return 0;
}
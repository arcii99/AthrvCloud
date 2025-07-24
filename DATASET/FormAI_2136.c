//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char pixels[ROWS][COLS];

void generatePixels() { // generate random pixels
    srand(time(NULL)); // seed random number generator
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            int val = rand() % 16;
            pixels[row][col] = val < 10 ? '0' + val : 'A' + (val - 10);
        }
    }
}

void printPixels() { // print pixels as ascii art
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            printf("%c ", pixels[row][col]);
        }
        printf("\n");
    }
}

int main() {
    generatePixels();
    printPixels();
    return 0;
}
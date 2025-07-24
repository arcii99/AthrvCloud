//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

char PIXELS[HEIGHT][WIDTH];

void generatePixels() {
    srand(time(NULL)); // seed random number generator

    // generate pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int chance = rand() % 100;

            if (chance < 20) {
                PIXELS[y][x] = ' ';
            } else if (chance < 40) {
                PIXELS[y][x] = '.';
            } else if (chance < 60) {
                PIXELS[y][x] = '*';
            } else if (chance < 80) {
                PIXELS[y][x] = '+';
            } else {
                PIXELS[y][x] = '#';
            }
        }
    }
}

void printPixels() {
    // print pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", PIXELS[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generatePixels();
    printPixels();

    return 0;
}
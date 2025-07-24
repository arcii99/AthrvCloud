//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void createPixelArt(char art[HEIGHT][WIDTH]) {
    int i, j;
    srand(time(0)); // Use the current time as seed for random number generator

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int r = rand() % 100;
            if (r < 25) {
                art[i][j] = '#'; // Generate a pixel with a probability of 25%
            }
            else {
                art[i][j] = ' '; // Generate an empty space otherwise
            }
        }
    }
}

void printPixelArt(char art[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char art[HEIGHT][WIDTH];
    createPixelArt(art);
    printPixelArt(art);
    return 0;
}
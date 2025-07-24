//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(char art[8][8]) {

    int i, j;

    // Generate random pixel art
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (rand() % 2 == 0) {
                art[i][j] = '#'; // black pixel
            } else {
                art[i][j] = '-'; // white pixel
            }
        }
    }

    // Add some color
    int color = rand() % 7;
    switch (color) {
        case 0:
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (art[i][j] == '#') {
                        art[i][j] = 'R'; // red pixel
                    }
                }
            }
            break;
        case 1:
            // add code for other colors...
            break;
        default:
            break;
    }
}

void printPixelArt(char art[8][8]) {

    int i, j;

    // Print pixel art to console
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", art[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Seed random number generator
    srand(time(NULL));

    // Generate and print pixel art
    char art[8][8];
    generatePixelArt(art);
    printPixelArt(art);

    return 0;
}
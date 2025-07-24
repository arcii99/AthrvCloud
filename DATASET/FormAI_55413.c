//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

char pixelArt[HEIGHT][WIDTH];

void generatePixelArt() {
    // seed the random number generator with the current time
    srand(time(NULL));
    
    // fill the pixelArt array with random colors
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            // pick a random color from the following options: R(ed), G(reen), B(lue), Y(ellow), P(ink), O(range)
            char color = rand() % 6;
            switch(color) {
                case 0:
                    pixelArt[y][x] = 'R';
                    break;
                case 1:
                    pixelArt[y][x] = 'G';
                    break;
                case 2:
                    pixelArt[y][x] = 'B';
                    break;
                case 3:
                    pixelArt[y][x] = 'Y';
                    break;
                case 4:
                    pixelArt[y][x] = 'P';
                    break;
                case 5:
                    pixelArt[y][x] = 'O';
                    break;
            }
        }
    }
}

void printPixelArt() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%c", pixelArt[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generatePixelArt();
    printPixelArt();
    return 0;
}
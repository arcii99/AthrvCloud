//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32

void generatePixelArt(char pixelArt[][WIDTH]) {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            int color = rand() % 6;
            switch(color) {
                case 0:
                    pixelArt[i][j] = 'R';
                    break;
                case 1:
                    pixelArt[i][j] = 'G';
                    break;
                case 2:
                    pixelArt[i][j] = 'B';
                    break;
                case 3:
                    pixelArt[i][j] = 'Y';
                    break;
                case 4:
                    pixelArt[i][j] = 'P';
                    break;
                case 5:
                    pixelArt[i][j] = 'O';
                    break;
            }
        }
    }
}

void printPixelArt(char pixelArt[][WIDTH]) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixelArt[HEIGHT][WIDTH];
    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);
    return 0;
}
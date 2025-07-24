//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void generatePixelArt(int pixelArt[][WIDTH], int width, int height) {
    srand(time(NULL));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            pixelArt[i][j] = rand() % 2;
        }
    }
}

void displayPixelArt(int pixelArt[][WIDTH], int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(pixelArt[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int pixelArt[HEIGHT][WIDTH];
    generatePixelArt(pixelArt, WIDTH, HEIGHT);
    displayPixelArt(pixelArt, WIDTH, HEIGHT);
    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void drawPixel(char pixel) {
    printf("%c", pixel);
}

void drawImage(char image[][WIDTH], int height) {
    for (int row=0; row<height; row++) {
        for (int col=0; col<WIDTH; col++) {
            drawPixel(image[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void generateImage(char image[][WIDTH], int height) {
    for (int row=0; row<height; row++) {
        for (int col=0; col<WIDTH; col++) {
            int randNum = rand() % 2;
            if (randNum == 0) {
                image[row][col] = '.';
            } else {
                image[row][col] = 'X';
            }
        }
    }
}

int main() {
    srand(time(NULL));
    char image[HEIGHT][WIDTH];
    generateImage(image, HEIGHT);
    drawImage(image, HEIGHT);
    return 0;
}
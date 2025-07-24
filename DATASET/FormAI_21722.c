//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void generatePixels(char pixels[WIDTH][HEIGHT]) {
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(rand() % 2 == 0) {
                pixels[i][j] = 'X';
            } else {
                pixels[i][j] = 'O';
            }
        }
    }
}

void printPixels(char pixels[WIDTH][HEIGHT]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixels[WIDTH][HEIGHT];
    generatePixels(pixels);
    printPixels(pixels);
    return 0;
}
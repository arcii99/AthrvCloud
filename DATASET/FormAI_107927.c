//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// set grid dimensions
#define HEIGHT 8
#define WIDTH 8

// function to generate random pixel art
void generatePixelArt(char grid[HEIGHT][WIDTH]) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            int random = rand() % 10;
            if(random >= 7) // 30% chance to draw a pixel
                grid[i][j] = '.';
            else
                grid[i][j] = ' ';
        }
    }
}

// function to print the generated pixel art
void printPixelArt(char grid[HEIGHT][WIDTH]) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    char grid[HEIGHT][WIDTH];
    generatePixelArt(grid);
    printPixelArt(grid);
    return 0;
}
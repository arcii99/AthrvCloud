//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void pixel_art(int pixel[HEIGHT][WIDTH]);

int main() {
    int pixel[HEIGHT][WIDTH] = {0};

    srand(time(NULL)); // seed the random generator

    // generate random pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0) { // 50% chance of being colored
                pixel[i][j] = rand() % 8 + 1; // random color between 1 and 8
            }
        }
    }

    // display pixel art
    pixel_art(pixel);

    return 0;
}

void pixel_art(int pixel[HEIGHT][WIDTH]) {
    char colors[] = {' ', '.', ':', 'o', '&', '8', '#', '@', '%'}; // ASCII art characters representing colors

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", colors[pixel[i][j]]);
        }
        printf("\n");
    }
}
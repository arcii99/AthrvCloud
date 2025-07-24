//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_COLOR 255
#define MIN_COLOR 0

void generate_pixels(int pixels[][WIDTH], int rows, int columns) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            pixels[i][j] = rand() % (MAX_COLOR - MIN_COLOR + 1) + MIN_COLOR;
        }
    }
}

void print_pixels(int pixels[][WIDTH], int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%c", pixels[i][j] > (MAX_COLOR / 2) ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int pixels[HEIGHT][WIDTH];
    generate_pixels(pixels, HEIGHT, WIDTH);
    print_pixels(pixels, HEIGHT, WIDTH);
    return 0;
}
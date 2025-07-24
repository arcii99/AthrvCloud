//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

int pixelart[WIDTH][HEIGHT];

int random_color() {
    return rand() % 255;
}

void initialize() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixelart[i][j] = random_color();
        }
    }
}

void print_pixelart() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", pixelart[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initialize();
    print_pixelart();
    return 0;
}
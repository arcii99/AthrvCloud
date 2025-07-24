//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define PIXEL_SIZE 5

void generate_pixel_art(char pixel_art[HEIGHT][WIDTH], int color) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pixel_art[i][j] = color;
        }
    }
}

void print_pixel_art(char pixel_art[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (pixel_art[i][j] == 0) {
                printf(" ");
            } else {
                printf("%c", pixel_art[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char pixel_art[HEIGHT][WIDTH];
    int color, i, j;

    srand(time(NULL));

    color = rand() % 256;

    generate_pixel_art(pixel_art, color);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0) {
                pixel_art[i][j] = 0;
            }
        }
    }

    print_pixel_art(pixel_art);

    return 0;
}
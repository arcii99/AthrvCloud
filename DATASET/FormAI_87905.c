//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_pixels(int pixels[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            pixels[i][j] = 0;
        }
    }
}

void print_pixels(int pixels[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
}

void set_pixel(int pixels[8][8], int x, int y, int value) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        pixels[x][y] = value;
    }
}

void generate_art(int pixels[8][8]) {
    int i, j, x, y, value;
    srand(time(NULL));
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            x = rand() % 8;
            y = rand() % 8;
            value = rand() % 2;
            set_pixel(pixels, x, y, value);
        }
    }
}

int main() {
    int pixels[8][8];
    init_pixels(pixels);
    generate_art(pixels);
    print_pixels(pixels);
    return 0;
}
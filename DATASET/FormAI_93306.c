//FormAI DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h> 

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

void print_screen(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void set_pixel(char screen[SCREEN_HEIGHT][SCREEN_WIDTH], int x, int y, char color) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        screen[y][x] = color;
    }
}

void fractal(char screen[SCREEN_HEIGHT][SCREEN_WIDTH], int x, int y, int size) {
    if (size == 1) {
        set_pixel(screen, x, y, '*');
    } else {
        fractal(screen, x - size / 2, y - size / 2, size / 2);
        fractal(screen, x + size / 2, y - size / 2, size / 2);
        fractal(screen, x - size / 2, y + size / 2, size / 2);
        fractal(screen, x + size / 2, y + size / 2, size / 2);
    }
}

int main() {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }

    fractal(screen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_HEIGHT);
    print_screen(screen);

    return 0;
}
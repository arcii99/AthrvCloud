//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 128
#define HEIGHT 128

#define MAX_COLOR 15

typedef enum {
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7,
    GRAY = 8,
    DARK_RED = 9,
    DARK_GREEN = 10,
    DARK_YELLOW = 11,
    DARK_BLUE = 12,
    DARK_MAGENTA = 13,
    DARK_CYAN = 14,
    LIGHT_GRAY = 15,
} Color;

void generate_pixel_art(Color pixels[WIDTH][HEIGHT]);
void print_pixels(Color pixels[WIDTH][HEIGHT]);

int main() {
    Color pixels[WIDTH][HEIGHT];

    srand(time(NULL));
    generate_pixel_art(pixels);
    print_pixels(pixels);

    return 0;
}

void generate_pixel_art(Color pixels[WIDTH][HEIGHT]) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            pixels[x][y] = rand() % MAX_COLOR;
        }
    }
}

void print_pixels(Color pixels[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            switch (pixels[x][y]) {
                case BLACK:
                    printf(" ");
                    break;
                case RED:
                    printf("\033[0;31m*\033[0m"); // red
                    break;
                case GREEN:
                    printf("\033[0;32m*\033[0m"); // green
                    break;
                case YELLOW:
                    printf("\033[0;33m*\033[0m"); // yellow
                    break;
                case BLUE:
                    printf("\033[0;34m*\033[0m"); // blue
                    break;
                case MAGENTA:
                    printf("\033[0;35m*\033[0m"); // magenta
                    break;
                case CYAN:
                    printf("\033[0;36m*\033[0m"); // cyan
                    break;
                case WHITE:
                    printf("\033[0;37m*\033[0m"); // white
                    break;
                case GRAY:
                    printf("\033[1;30m*\033[0m"); // gray
                    break;
                case DARK_RED:
                    printf("\033[1;31m*\033[0m"); // dark red
                    break;
                case DARK_GREEN:
                    printf("\033[1;32m*\033[0m"); // dark green
                    break;
                case DARK_YELLOW:
                    printf("\033[1;33m*\033[0m"); // dark yellow
                    break;
                case DARK_BLUE:
                    printf("\033[1;34m*\033[0m"); // dark blue
                    break;
                case DARK_MAGENTA:
                    printf("\033[1;35m*\033[0m"); // dark magenta
                    break;
                case DARK_CYAN:
                    printf("\033[1;36m*\033[0m"); // dark cyan
                    break;
                case LIGHT_GRAY:
                    printf("\033[1;37m*\033[0m"); // light gray
                    break;
            }
        }
        printf("\n");
    }
}
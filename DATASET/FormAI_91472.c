//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define PIXEL_SIZE 2

void draw_pixel(int x, int y, char pixel[PIXEL_SIZE][PIXEL_SIZE]);

int main() {
    char pixels[WIDTH][HEIGHT][PIXEL_SIZE][PIXEL_SIZE];
    srand(time(NULL));

    // Generate random pixel art
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            for (int i = 0; i < PIXEL_SIZE; i++) {
                for (int j = 0; j < PIXEL_SIZE; j++) {
                    if (rand() % 2 == 0) {
                        pixels[x][y][i][j] = '#';
                    } else {
                        pixels[x][y][i][j] = ' ';
                    }
                }
            }
        }
    }

    // Draw the pixel art
    for (int y = 0; y < HEIGHT * PIXEL_SIZE; y++) {
        for (int x = 0; x < WIDTH * PIXEL_SIZE; x++) {
            int pixel_x = x / PIXEL_SIZE;
            int pixel_y = y / PIXEL_SIZE;

            draw_pixel(x, y, pixels[pixel_x][pixel_y]);
        }
        printf("\n");
    }

    return 0;
}

void draw_pixel(int x, int y, char pixel[PIXEL_SIZE][PIXEL_SIZE]) {
    printf("%c", pixel[x % PIXEL_SIZE][y % PIXEL_SIZE]);
}
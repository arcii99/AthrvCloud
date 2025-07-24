//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10 // width of canvas
#define HEIGHT 10 // height of canvas
#define PIXEL_SIZE 2 // size of each pixel in characters
#define MAX_COLOR 7 // maximum color value

void set_pixel(char canvas[][WIDTH * PIXEL_SIZE], int row, int col, int color) {
    // converts color value to corresponding character
    char pixel_color = '0' + color;

    // sets pixels in canvas array
    for (int i = 0; i < PIXEL_SIZE; i++) {
        for (int j = 0; j < PIXEL_SIZE; j++) {
            canvas[row * PIXEL_SIZE + i][col * PIXEL_SIZE + j] = pixel_color;
        }
    }
}

int main() {
    char canvas[HEIGHT * PIXEL_SIZE][WIDTH * PIXEL_SIZE]; // 2D array to store canvas

    // initializes canvas array with spaces
    for (int i = 0; i < HEIGHT * PIXEL_SIZE; i++) {
        for (int j = 0; j < WIDTH * PIXEL_SIZE; j++) {
            canvas[i][j] = ' ';
        }
    }

    // sets seed for random number generation
    srand(time(NULL));

    // generates a random pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int color = rand() % MAX_COLOR; // generates random color value
            set_pixel(canvas, i, j, color); // sets pixel on canvas
        }
    }

    // prints canvas to console
    for (int i = 0; i < HEIGHT * PIXEL_SIZE; i++) {
        for (int j = 0; j < WIDTH * PIXEL_SIZE; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n"); // moves to next row
    }

    return 0;
}
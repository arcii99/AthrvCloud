//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 80
#define HEIGHT 25
#define PIXEL_SIZE 4

void set_pixel(char* canvas, int x, int y, char color);

int main() {
    char canvas[WIDTH * HEIGHT * PIXEL_SIZE];
    memset(canvas, ' ', sizeof(canvas)); // Fill the canvas with blank spaces

    // Set random pixels in the canvas
    for (int i = 0; i < WIDTH * HEIGHT * PIXEL_SIZE; i+=PIXEL_SIZE) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        char color = rand() % 2 == 0 ? '#' : ' ';
        set_pixel(canvas, x, y, color);
    }

    // Print the canvas to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH * PIXEL_SIZE; x += PIXEL_SIZE) {
            printf("%c%c%c%c", canvas[x + (y * WIDTH * PIXEL_SIZE)],
                   canvas[x + 1 + (y * WIDTH * PIXEL_SIZE)],
                   canvas[x + 2 + (y * WIDTH * PIXEL_SIZE)],
                   canvas[x + 3 + (y * WIDTH * PIXEL_SIZE)]);
        }
        printf("\n");
    }

    return 0;
}

void set_pixel(char* canvas, int x, int y, char color) {
    int pixel_index = x * PIXEL_SIZE + (y * WIDTH * PIXEL_SIZE);
    canvas[pixel_index] = color;
    canvas[pixel_index + 1] = color;
    canvas[pixel_index + 2] = color;
    canvas[pixel_index + 3] = color;
}
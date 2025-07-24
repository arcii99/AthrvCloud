//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10

int canvas[WIDTH][HEIGHT];

void draw_pixel(int x, int y, int color) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[x][y] = color;
    }
}

void clear_canvas() {
    memset(canvas, 0, sizeof(canvas));
}

void print_canvas() {
    int x, y;
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            printf("%d ", canvas[x][y]);
        }
        printf("\n");
    }
}

int main() {
    clear_canvas();

    // Draw a smiley face
    draw_pixel(3, 4, 1);
    draw_pixel(6, 4, 1);
    draw_pixel(2, 5, 1);
    draw_pixel(7, 5, 1);
    draw_pixel(3, 6, 1);
    draw_pixel(4, 6, 1);
    draw_pixel(5, 6, 1);

    print_canvas();

    return 0;
}
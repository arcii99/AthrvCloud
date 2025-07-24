//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

void draw_pixel(int r, int g, int b) {
    printf("\x1b[48;2;%d;%d;%dm  ", r, g, b);
}

void draw_line(int x1, int y1, int x2, int y2, int r, int g, int b, int pixels[WIDTH][HEIGHT]) {
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        pixels[x1][y1] = 1;
        draw_pixel(r, g, b); // Actual output to console
        if (x1 == x2 && y1 == y2) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

void generate_art() {
    int pixels[WIDTH][HEIGHT] = {{0}}; // Initialize the array to all 0's
    int num_lines = rand() % 50 + 50; // Choose a random number of lines to draw

    for (int i = 0; i < num_lines; i++) {
        int x1 = rand() % WIDTH;
        int y1 = rand() % HEIGHT;
        int x2 = rand() % WIDTH;
        int y2 = rand() % HEIGHT;
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        draw_line(x1, y1, x2, y2, r, g, b, pixels);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    generate_art();
    return 0;
}
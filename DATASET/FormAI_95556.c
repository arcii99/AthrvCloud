//FormAI DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_DEPTH 25
#define WIDTH 120
#define HEIGHT 40

char img[HEIGHT][WIDTH];

void clear_image() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            img[i][j] = ' ';
        }
    }
}

void print_image() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            putchar(img[i][j]);
        }
        putchar('\n');
    }
}

void draw_line(int x1, int y1, int x2, int y2, int depth) {
    if(depth > MAX_DEPTH) {
        return;
    }

    if(x1 == x2 && y1 == y2) {
        img[y1][x1] = '*';
    } else {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float x = x1;
        float y = y1;
        float x_inc = dx / (float) steps;
        float y_inc = dy / (float) steps;
        for(int i = 0; i <= steps; i++) {
            img[(int) round(y)][(int) round(x)] = '*';
            x += x_inc;
            y += y_inc;
        }

        int mx = (x1 + x2) / 2;
        int my = (y1 + y2) / 2;
        int rx = (int) ((rand() / (float) RAND_MAX) * 30) - 15;
        int ry = (int) ((rand() / (float) RAND_MAX) * 30) - 15;
        draw_line(x1, y1, mx + rx, my + ry, depth + 1);
        draw_line(x2, y2, mx + rx, my + ry, depth + 1);
    }
}

int main() {
    srand(time(NULL));
    clear_image();
    draw_line(0, HEIGHT/2, WIDTH-1, HEIGHT/2, 1);
    print_image();
    return 0;
}
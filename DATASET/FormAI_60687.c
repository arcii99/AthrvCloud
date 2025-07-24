//FormAI DATASET v1.0 Category: Fractal Generation ; Style: genious
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct {
    int x, y;
} point;

void set_pixel(point p, char* buffer) {
    buffer[p.x + p.y * WIDTH] = 1;
}

void draw_line(point a, point b, char* buffer) {
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    int sx = a.x < b.x ? 1 : -1;
    int sy = a.y < b.y ? 1 : -1;
    int err = dx - dy;
    while(!(a.x == b.x && a.y == b.y)) {
        set_pixel(a, buffer);
        int e2 = 2 * err;
        if(e2 > -dy) {
            err -= dy;
            a.x += sx;
        }
        if(e2 < dx) {
            err += dx;
            a.y += sy;
        }
    }
    set_pixel(b, buffer);
}

void draw_box(int x_min, int y_min, int x_max, int y_max, char* buffer) {
    draw_line((point){x_min, y_min}, (point){x_min, y_max}, buffer);
    draw_line((point){x_min, y_min}, (point){x_max, y_min}, buffer);
    draw_line((point){x_min, y_max}, (point){x_max, y_max}, buffer);
    draw_line((point){x_max, y_min}, (point){x_max, y_max}, buffer);
}

void draw_fractal_box(int x_min, int y_min, int x_max, int y_max, char* buffer) {

    draw_box(x_min, y_min, x_max, y_max, buffer);

    int width = x_max - x_min;
    int height = y_max - y_min;

    if(width > 10 && height > 10) {

        int split_x = (rand() % (width - 8)) + 4;
        int split_y = (rand() % (height - 8)) + 4;

        draw_fractal_box(x_min, y_min, x_min + split_x, y_min + split_y, buffer);
        draw_fractal_box(x_min + split_x, y_min, x_max, y_min + split_y, buffer);
        draw_fractal_box(x_min, y_min + split_y, x_min + split_x, y_max, buffer);
        draw_fractal_box(x_min + split_x, y_min + split_y, x_max, y_max, buffer);
    }
}

void display(char* buffer) {
    for(int j = 0; j < HEIGHT; ++j) {
        for(int i = 0; i < WIDTH; ++i) {
            putchar(buffer[i + j * WIDTH] ? '*' : '.');
        }
        putchar('\n');
    }
}

int main() {

    srand(time(NULL));
    char buffer[WIDTH * HEIGHT] = {0};
    draw_fractal_box(20, 20, WIDTH - 20, HEIGHT - 20, buffer);
    display(buffer);
    return 0;
}
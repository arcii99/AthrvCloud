//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

char matrix[HEIGHT][WIDTH];

void initialize_matrix() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void print_matrix() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void draw_pixel(int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        matrix[y][x] = 'X';
    }
}

void draw_square(int x, int y, int size) {
    int i, j;
    for (i = y; i < y + size; i++) {
        for (j = x; j < x + size; j++) {
            draw_pixel(j, i);
        }
    }
}

void draw_triangle(int x, int y, int size) {
    int i, j;
    for (i = y; i < y + size; i++) {
        for (j = x - (i - y); j <= x + (i - y); j++) {
            draw_pixel(j, i);
        }
    }
}

void draw_circle(int x, int y, int radius) {
    int i, j;
    for (i = y - radius; i <= y + radius; i++) {
        for (j = x - radius; j <= x + radius; j++) {
            if ((i - y) * (i - y) + (j - x) * (j - x) <= radius * radius) {
                draw_pixel(j, i);
            }
        }
    }
}

int rand_int(int max_value) {
    return rand() % max_value;
}

void draw_random_pixels(int count) {
    int i;
    for (i = 0; i < count; i++) {
        draw_pixel(rand_int(WIDTH), rand_int(HEIGHT));
    }
}

int main() {
    srand(time(NULL));
    initialize_matrix();
    draw_square(1, 1, 3);
    draw_triangle(5, 3, 5);
    draw_circle(8, 8, 4);
    draw_random_pixels(10);
    print_matrix();
    return 0;
}
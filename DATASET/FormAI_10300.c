//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int main() {
    srand(time(NULL));
    char pixels[WIDTH][HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[x][y] = ' ';
        }
    }
    int num_shapes = rand() % 6 + 3;
    for (int i = 0; i < num_shapes; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int shape_type = rand() % 3;
        char shape_char;
        int shape_size_x, shape_size_y;
        switch (shape_type) {
            case 0:
                // rectangle
                shape_char = '#';
                shape_size_x = rand() % 10 + 1;
                shape_size_y = rand() % 10 + 1;
                break;
            case 1:
                // triangle
                shape_char = '^';
                shape_size_x = rand() % 10 + 1;
                shape_size_y = shape_size_x;
                break;
            case 2:
                // circle
                shape_char = 'O';
                shape_size_x = rand() % 10 + 1;
                shape_size_y = shape_size_x;
                break;
        }
        for (int dy = 0; dy < shape_size_y; dy++) {
            for (int dx = 0; dx < shape_size_x; dx++) {
                int gx = x + dx;
                int gy = y + dy;
                if (gx >= 0 && gx < WIDTH && gy >= 0 && gy < HEIGHT && pixels[gx][gy] == ' ') {
                    pixels[gx][gy] = shape_char;
                }
            }
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", pixels[x][y]);
        }
        printf("\n");
    }
    return 0;
}
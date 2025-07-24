//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: curious
#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

unsigned char canvas[HEIGHT][WIDTH][3];

void update_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    canvas[y][x][0] = r;
    canvas[y][x][1] = g;
    canvas[y][x][2] = b;
}

void print_canvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            unsigned char r = canvas[i][j][0];
            unsigned char g = canvas[i][j][1];
            unsigned char b = canvas[i][j][2];
            if (r + g + b > 500) {
                printf("*");
            } else if (r > g && r > b) {
                printf("R");
            } else if (g > r && g > b) {
                printf("G");
            } else {
                printf("B");
            }
        }
        printf("\n");
    }
}

int main() {
    update_pixel(0, 0, 255, 255, 255);
    update_pixel(1, 1, 255, 0, 0);
    update_pixel(2, 2, 0, 255, 0);
    update_pixel(3, 3, 0, 0, 255);
    print_canvas();
    return 0;
}
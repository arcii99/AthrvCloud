//FormAI DATASET v1.0 Category: Fractal Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 80

int image[HEIGHT][WIDTH];

void draw_fractal(int x1, int y1, int x2, int y2) {
    if ((x2-x1) + (y2-y1) < 2) {
        return;
    }
    int cx = (x1 + x2) / 2;
    int cy = (y1 + y2) / 2;
    int value = rand() % 256;
    image[cy][cx] = value;
    draw_fractal(x1, y1, cx, cy);
    draw_fractal(cx, y1, x2, cy);
    draw_fractal(x1, cy, cx, y2);
    draw_fractal(cx, cy, x2, y2);
}

int main() {
    srand(time(NULL));
    draw_fractal(0, 0, WIDTH-1, HEIGHT-1);
    
    // print image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (image[y][x] < 128) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
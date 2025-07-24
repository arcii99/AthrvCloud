//FormAI DATASET v1.0 Category: Fractal Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

unsigned char pixels[WIDTH][HEIGHT];

void drawFractal(int x1, int y1, int x2, int y2, int depth) {
    if(depth == 0) {
        return;
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x3 = x2 - dy;
    int y3 = y2 + dx;
    int x4 = x1 - dy;
    int y4 = y1 + dx;
    int nx = (x1 + x2 + x3 + x4) / 4;
    int ny = (y1 + y2 + y3 + y4) / 4;
    pixels[nx][ny] = 1;
    drawFractal(x1, y1, x4, y4, depth - 1);
    drawFractal(x4, y4, x3, y3, depth - 1);
    drawFractal(x3, y3, x2, y2, depth - 1);
    drawFractal(x2, y2, x1, y1, depth - 1);
}

int main() {
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            pixels[i][j] = 0;
        }
    }
    drawFractal(100, 400, 200, 400, 10);
    drawFractal(200, 400, 200, 300, 10);
    drawFractal(200, 300, 100, 300, 10);
    drawFractal(100, 300, 100, 400, 10);
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            if(pixels[i][j] == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: retro
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 25

void drawPixel(char canvas[HEIGHT][WIDTH], int x, int y, char color) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = color;
    }
}

void drawLine(char canvas[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, char color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    int e2;
    
    while(1) {
        drawPixel(canvas, x1, y1, color);
        if(x1 == x2 && y1 == y2) {
            break;
        }
        e2 = err * 2;
        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRect(char canvas[HEIGHT][WIDTH], int x, int y, int width, int height, char color) {
    drawLine(canvas, x, y, x + width - 1, y, color);
    drawLine(canvas, x + width - 1, y, x + width - 1, y + height - 1, color);
    drawLine(canvas, x + width - 1, y + height - 1, x, y + height - 1, color);
    drawLine(canvas, x, y + height - 1, x, y, color);
}

void drawCircle(char canvas[HEIGHT][WIDTH], int cx, int cy, int r, char color) {
    int x = -r;
    int y = 0;
    int err = 2 - 2 * r;
    do {
        drawPixel(canvas, cx - x, cy + y, color);
        drawPixel(canvas, cx - y, cy - x, color);
        drawPixel(canvas, cx + x, cy - y, color);
        drawPixel(canvas, cx + y, cy + x, color);
        r = err;
        if(r <= y) {
            err += ++y * 2 + 1;
        }
        if(r > x || err > y) {
            err += ++x * 2 + 1;
        }
    } while(x < 0); 
}

int main() {
    char canvas[HEIGHT][WIDTH];
    int x, y;
    srand(time(NULL));
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            canvas[y][x] = ' ';
        }
    }
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            if(rand() % 100 < 5) {
                drawPixel(canvas, x, y, '0' + rand() % 10);
            }
        }
    }
    drawRect(canvas, 10, 5, 30, 15, 'X');
    drawCircle(canvas, 25, 15, 10, 'O');
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            putchar(canvas[y][x]);
        }
        putchar('\n');
    }
    return 0;
}
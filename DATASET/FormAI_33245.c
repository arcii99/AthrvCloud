//FormAI DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>

#define WIDTH 50
#define HEIGHT 25

void drawLine(char arr[][WIDTH], int x1, int y1, int x2, int y2, char c) {
    if(x1 == x2) {
        for(int y = y1; y <= y2; y++) {
            arr[y][x1] = c;
        }
    } else if(y1 == y2) {
        for(int x = x1; x <= x2; x++) {
            arr[y1][x] = c;
        }
    }
}

void recursiveDraw(char arr[][WIDTH], int x1, int y1, int x2, int y2) {
    if(x2 - x1 < 2 || y2 - y1 < 2) {
        return;
    }
    int midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
    drawLine(arr, x1, midy, x2, midy, '*');
    drawLine(arr, midx, y1, midx, y2, '*');
    recursiveDraw(arr, x1, y1, midx, midy);
    recursiveDraw(arr, midx, y1, x2, midy);
    recursiveDraw(arr, x1, midy, midx, y2);
    recursiveDraw(arr, midx, midy, x2, y2);
}

int main() {
    char arr[HEIGHT][WIDTH];
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            arr[y][x] = ' ';
        }
    }
    recursiveDraw(arr, 0, 0, WIDTH - 1, HEIGHT - 1);
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%c", arr[y][x]);
        }
        printf("\n");
    }
    return 0;
}
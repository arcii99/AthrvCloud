//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>

const int WIDTH = 10;
const int HEIGHT = 10;
int map[10][10]; 

void drawPixel(int x, int y) {
    map[y][x] = 1;
}

void printMap() {
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            printf("%c ", map[row][col] == 1 ? '*' : ' ');
        }
        printf("\n");
    }
}

void generatePixelArt() {
    drawPixel(1, 1);
    drawPixel(2, 1);
    drawPixel(3, 1);
    drawPixel(1, 3);
    drawPixel(2, 3);
    drawPixel(3, 3);
    drawPixel(1, 5);
    drawPixel(2, 5);
    drawPixel(3, 5);
}

int main() {
    generatePixelArt();
    printMap();
    return 0;
}
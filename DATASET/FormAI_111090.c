//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50

void drawPixel(char pixels[][WIDTH], int x, int y, char color)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    pixels[y][x] = color;
}

void drawBlock(char pixels[][WIDTH], int x, int y, int size, char color)
{
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            drawPixel(pixels, i, j, color);
        }
    }
}

void generatePixelArt(char pixels[][WIDTH])
{
    srand(time(NULL));

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int r = rand() % 100;
            if (r < 20) {
                pixels[i][j] = ' ';
            } else if (r < 30) {
                pixels[i][j] = '=';
            } else if (r < 40) {
                pixels[i][j] = '-';
            } else {
                pixels[i][j] = '#';
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        int x = rand() % (WIDTH - 5);
        int y = rand() % (HEIGHT - 5);
        int size = rand() % 5 + 2;
        char color = '1' + rand() % 6;
        drawBlock(pixels, x, y, size, color);
    }
}

void printPixelArt(char pixels[][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char pixels[HEIGHT][WIDTH];
    generatePixelArt(pixels);
    printPixelArt(pixels);
    return 0;
}
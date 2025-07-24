//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Color {
    int r, g, b;
} Color;

void setPixel(Color canvas[WIDTH][HEIGHT], int row, int col, Color color) {
    canvas[row][col] = color;
}

Color makeColor(int r, int g, int b) {
    Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    return color;
}

Color getRandomColor() {
    Color color;
    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    return color;
}

void printCanvas(Color canvas[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("(%d, %d, %d)\t", canvas[i][j].r, canvas[i][j].g, canvas[i][j].b);
        }
        printf("\n");
    }
}

void generatePixelArt(Color canvas[WIDTH][HEIGHT], int numColors) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            setPixel(canvas, i, j, getRandomColor());
        }
    }
    Color uniqueColors[numColors];
    int numUniqueColors = 0;
    while (numUniqueColors < numColors) {
        Color color = getRandomColor();
        int isUnique = 1;
        for (int i = 0; i < numUniqueColors; i++) {
            if (uniqueColors[i].r == color.r && uniqueColors[i].g == color.g && uniqueColors[i].b == color.b) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            uniqueColors[numUniqueColors] = color;
            numUniqueColors++;
        }
    }
    for (int i = 0; i < numColors; i++) {
        int row = rand() % HEIGHT;
        int col = rand() % WIDTH;
        setPixel(canvas, row, col, uniqueColors[i]);
    }
}

int main() {
    Color canvas[WIDTH][HEIGHT];
    generatePixelArt(canvas, 5);
    printCanvas(canvas);
    return 0;
}
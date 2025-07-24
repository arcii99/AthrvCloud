//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

void setPixel(char matrix[WIDTH][HEIGHT], int x, int y, char pixelType) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        matrix[x][y] = pixelType;
    }
}

void generatePixelArt(char matrix[WIDTH][HEIGHT]) {
    int x, y;
    char pixelTypes[5] = {' ', '.', '+', '*', '#'};

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            int pixelTypeIndex = rand() % 5;
            setPixel(matrix, x, y, pixelTypes[pixelTypeIndex]);
        }
    }
}

int main() {
    char pixelMatrix[WIDTH][HEIGHT];
    srand(time(NULL));

    generatePixelArt(pixelMatrix);

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", pixelMatrix[x][y]);
        }
        printf("\n");
    }

    return 0;
}
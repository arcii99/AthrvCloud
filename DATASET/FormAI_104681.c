//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 60

void printAsciiArt(char pixels[][WIDTH], double min, double max) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            double val = (double) pixels[i][j];
            char ch;
            if (val < min) {
                ch = ' ';
            } else if (val > max) {
                ch = '*';
            } else {
                ch = '0' + round((val - min) * 9 / (max - min));
            }
            putchar(ch);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    char grayscalePixels[HEIGHT][WIDTH];
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            double x = (double) j / WIDTH * 10 - 5;
            double y = (double) i / HEIGHT * 10 - 5;
            double z = cos(sqrt(x * x + y * y)) / sqrt(x * x + y * y + 1);
            grayscalePixels[i][j] = (char) round((z + 1) * 127.5);
        }
    }

    printAsciiArt(grayscalePixels, 0, 255);
    
    return 0;
}
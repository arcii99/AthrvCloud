//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

char asciiArt[HEIGHT][WIDTH];

void clearAsciiArt() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            asciiArt[r][c] = ' ';
        }
    }
}

void printAsciiArt() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            printf("%c", asciiArt[r][c]);
        }
        printf("\n");
    }
}

void drawPixel(int r, int c, char ch) {
    if (r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH) {
        asciiArt[r][c] = ch;
    }
}

void drawLine(int r1, int c1, int r2, int c2, char ch) {
    int dr = r2 - r1;
    int dc = c2 - c1;
    if (dc == 0) {
        // Vertical line.
        int rMin = r1 < r2 ? r1 : r2;
        int rMax = r1 < r2 ? r2 : r1;
        for (int r = rMin; r <= rMax; r++) {
            drawPixel(r, c1, ch);
        }
    } else {
        // Diagonal line.
        int cMin = c1 < c2 ? c1 : c2;
        int cMax = c1 < c2 ? c2 : c1;
        for (int c = cMin; c <= cMax; c++) {
            int r = r1 + dr * (c - c1) / dc;  // Approximate row number.
            drawPixel(r, c, ch);
        }
    }
}

int main() {
    clearAsciiArt();
    drawLine(10, 5, 30, 50, '*');
    drawLine(10, 50, 30, 5, '*');
    drawLine(20, 5, 20, 50, '*');
    drawLine(5, 20, 35, 20, '*');
    drawLine(5, 60, 35, 60, '*');
    drawLine(5, 20, 5, 60, '*');
    drawLine(35, 20, 35, 60, '*');
    printAsciiArt();
    return 0;
}
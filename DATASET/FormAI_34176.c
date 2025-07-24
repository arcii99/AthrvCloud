//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>

#define WIDTH 16 // Number of pixels horizontally
#define HEIGHT 16 // Number of pixels vertically

char canvas[HEIGHT][WIDTH]; // Creates an empty pixel canvas

void clearCanvas() { // Fills the canvas with empty pixels
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            canvas[y][x] = ' ';
        }
    }
}

void printCanvas() { // Prints the pixel canvas to the console
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(canvas[y][x]);
        }
        putchar('\n'); // Adds a new line after each row
    }
}

void setPixel(int x, int y) { // Sets a pixel on the canvas at a specific location
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) { // Only sets the pixel if within canvas boundaries
        canvas[y][x] = 'x';
    }
}

// Example art piece
void drawArt() {
    setPixel(1, 1);
    setPixel(2, 1);
    setPixel(4, 1);
    setPixel(5, 1);
    setPixel(3, 2);
    setPixel(2, 3);
    setPixel(4, 3);
    setPixel(0, 4);
    setPixel(1, 4);
    setPixel(2, 5);
    setPixel(3, 6);
    setPixel(4, 7);
    setPixel(5, 6);
    setPixel(6, 5);
    setPixel(7, 4);
    setPixel(8, 3);
    setPixel(9, 4);
    setPixel(10, 5);
    setPixel(11, 6);
    setPixel(12, 7);
    setPixel(13, 6);
    setPixel(14, 5);
    setPixel(15, 4);
    setPixel(1, 7);
    setPixel(2, 7);
    setPixel(3, 7);
    setPixel(4, 7);
    setPixel(5, 7);
    setPixel(7, 7);
    setPixel(8, 7);
    setPixel(9, 7);
    setPixel(10, 7);
    setPixel(11, 7);
    setPixel(13, 7);
    setPixel(14, 7);
    setPixel(0, 9);
    setPixel(1, 8);
    setPixel(2, 9);
    setPixel(3, 10);
    setPixel(4, 11);
    setPixel(3, 12);
    setPixel(2, 13);
    setPixel(1, 14);
    setPixel(0, 15);
    setPixel(7, 9);
    setPixel(8, 9);
    setPixel(9, 9);
    setPixel(10, 9);
    setPixel(11, 9);
    setPixel(12, 9);
    setPixel(13, 9);
    setPixel(14, 9);
}

int main() {
    clearCanvas(); // Clears the canvas before drawing anything
    drawArt(); // Draws the art piece
    printCanvas(); // Prints the art piece to the console
    return 0;
}
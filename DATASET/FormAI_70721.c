//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define screen dimensions
#define WIDTH 40
#define HEIGHT 20

// Define color codes
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Define pixel structure
typedef struct Pixel {
    int color;
    char symbol;
} Pixel;

// Define pixel grid
Pixel pixels[WIDTH][HEIGHT];

/**
 * Helper function to clear the screen.
 */
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

/**
 * Helper function to set the pixel at (x, y) to the specified color and symbol.
 */
void setPixel(int x, int y, int color, char symbol) {
    pixels[x][y].color = color;
    pixels[x][y].symbol = symbol;
}

/**
 * Helper function to get a random color code.
 */
int getRandomColor() {
    int randomInt = rand() % 8;
    switch (randomInt) {
        case 0:
            return 30; // black
        case 1:
            return 31; // red
        case 2:
            return 32; // green
        case 3:
            return 33; // yellow
        case 4:
            return 34; // blue
        case 5:
            return 35; // magenta
        case 6:
            return 36; // cyan
        case 7:
            return 37; // white
    }
}

/**
 * Helper function to print the pixel grid.
 */
void printPixels() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("\033[%d;%dm%c\033[0m", pixels[x][y].color, pixels[x][y].color == 30 ? 47 : 40, pixels[x][y].symbol);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // initialize random seed

    // Fill pixels with spaces and randomly colored dots
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            setPixel(x, y, 30, ' ');
            if (rand() % 5 == 0) {
                setPixel(x, y, getRandomColor(), '.');
            }
        }
    }

    // Clear the screen and print the pixels
    clearScreen();
    printPixels();

    return 0;
}
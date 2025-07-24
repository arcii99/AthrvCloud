//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants
#define WIDTH 50
#define HEIGHT 30
#define NUM_COLORS 6

// Define a color structure to hold RGB values
typedef struct {
    int r;
    int g;
    int b;
} Color;

// Define an array of colors
Color colors[NUM_COLORS] = {
    {255, 255, 255}, // white
    {0, 0, 0},       // black
    {255, 0, 0},     // red
    {0, 255, 0},     // green
    {0, 0, 255},     // blue
    {255, 255, 0}    // yellow
};

// Function to draw a pixel of a certain color at a given location
void drawPixel(int x, int y, Color c) {
    printf("\033[%d;%dH\x1b[48;2;%d;%d;%dm \x1b[0m", y, x, c.r, c.g, c.b);
}

// Function to generate a random color
Color getRandomColor() {
    return colors[rand() % NUM_COLORS];
}

// Function to generate a random pixel art
void generatePixelArt() {
    srand(time(NULL)); // seed the random number generator
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color c = getRandomColor();
            drawPixel(x+1, y+1, c);
        }
    }
}

int main() {
    printf("\033[2J"); // clear the console
    generatePixelArt();
    return 0;
}
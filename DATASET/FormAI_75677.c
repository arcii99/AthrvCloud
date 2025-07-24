//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the screen dimensions and pixel size
#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 20
#define PIXEL_SIZE 2

// function to generate a random color
char* generateColor() {
    srand(time(NULL));
    char* color = (char*)malloc(8 * sizeof(char));
    sprintf(color, "#%06X", rand() % 0x1000000);
    return color;
}

// function to print a pixel
void printPixel(char* color) {
    printf("\033[48;2;%sm ", color);
    printf("\033[0m");
}

// function to generate a pixel art
void generatePixelArt() {
    char* screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    
    // initialize the screen with random colors
    for(int i = 0; i < SCREEN_HEIGHT; i++) {
        for(int j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = generateColor();
        }
    }
    
    // print the pixel art
    for(int i = 0; i < SCREEN_HEIGHT; i++) {
        for(int j = 0; j < SCREEN_WIDTH; j++) {
            for(int k = 0; k < PIXEL_SIZE; k++) {
                printPixel(screen[i][j]);
            }
        }
        printf("\n");
    }
}

// main function to run the program
int main() {
    generatePixelArt();
    return 0;
}
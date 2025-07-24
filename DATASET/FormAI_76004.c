//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the pixel art
#define WIDTH 10
#define HEIGHT 10

// Define the max color value (RGB)
#define MAX_COLOR 255

// Define the available pixel characters
#define PIXEL_CHARACTERS {'*', '+', '-', 'o', 'x', 'O', 'X', '#', '.', ' '}

// Define the pixel art structure
typedef struct {
    char pixels[WIDTH][HEIGHT];
    int colors[WIDTH][HEIGHT][3];
} PixelArt;

// Function to generate a random color
void generateRandomColor(int* color) {
    color[0] = rand() % (MAX_COLOR + 1);
    color[1] = rand() % (MAX_COLOR + 1);
    color[2] = rand() % (MAX_COLOR + 1);
}

// Function to generate a pixel art with random colors and characters
PixelArt generatePixelArt() {
    PixelArt pixelArt;
    char* pixelCharacters = PIXEL_CHARACTERS;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int randomCharacterIndex = rand() % 10; // Get a random pixel character index
            pixelArt.pixels[i][j] = pixelCharacters[randomCharacterIndex];

            generateRandomColor(pixelArt.colors[i][j]); // Generate a random color
        }
    }
    return pixelArt;
}

// Function to print a pixel art
void printPixelArt(PixelArt pixelArt) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Print the pixel character with its RGB color code
            printf("\033[38;2;%d;%d;%dm%c\033[0m", pixelArt.colors[i][j][0], pixelArt.colors[i][j][1], pixelArt.colors[i][j][2], pixelArt.pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for the random generator
    
    PixelArt pixelArt = generatePixelArt(); // Generate a random pixel art
    printPixelArt(pixelArt); // Print the pixel art
    
    return 0;
}
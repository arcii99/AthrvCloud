//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10 // Width of the canvas
#define HEIGHT 10 // Height of the canvas

/**
 * This function generates a random color code of the form "#RRGGBB"
 */
char* getRandomColor() {
    static char color[8];

    // Generate a random color in RGB format
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;

    // Format the color in "#RRGGBB" format
    sprintf(color, "#%02x%02x%02x", r, g, b);

    return color;
}

/**
 * This function generates a random pixel art
 */
void generatePixelArt() {
    // Clear the screen
    system("clear");

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Print the canvas
    printf(" ");
    for (int x = 0; x < WIDTH; x++) {
        printf("__");
    }
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            printf("%s ", getRandomColor());
        }
        printf("|\n");
    }

    printf(" ");
    for (int x = 0; x < WIDTH; x++) {
        printf("__");
    }
    printf("\n");
}

int main() {
    // Generate a random pixel art
    generatePixelArt();

    return 0;
}
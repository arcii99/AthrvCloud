//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32
#define MIN_COLOR 0
#define MAX_COLOR 255

// Function to generate a random color value
int rand_color() {
    return (rand() % (MAX_COLOR - MIN_COLOR)) + MIN_COLOR;
}

// Function to generate a random pixel art based on given color
void generate_pixel_art(int color) {
    int i, j;
    int pixel;

    // Loop through each pixel in the 2D array
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            // Generate a random color for the pixel
            pixel = rand_color();

            // If the random color matches the given color, use it
            if (pixel == color) {
                printf("X");
            } else {
                printf(".");
            }
        }

        // Move to the newline after each row
        printf("\n");
    }
}

int main() {
    int i;
    int color;
    srand(time(NULL)); // Seed the random generator with current time

    // Generate 5 random pixel art with different colors
    for (i = 0; i < 5; i++) {
        // Generate a random color for each pixel art
        color = rand_color();

        // Print the color and generate the pixel art
        printf("Pixel art with color %d:\n", color);
        generate_pixel_art(color);
        printf("\n");
    }

    return 0;
}
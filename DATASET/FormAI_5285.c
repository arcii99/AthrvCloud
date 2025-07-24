//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10            // Width of the Pixel Art
#define HEIGHT 10           // Height of the Pixel Art
#define COLOR_VALUES 256    // Number of possible color values
#define PIXEL_SIZE 2        // Size of each pixel

// Function to choose a random color value
int random_color() {
    return rand() % COLOR_VALUES;
}

// Function to generate the Pixel Art
void generate_pixel_art() {
    int pixel[HEIGHT][WIDTH][3];        // 3D array for RGB values
    int i, j, k, color;

    // Loop through each pixel in the array
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            for (k = 0; k < 3; k++) {
                // Choose a random RGB value for the pixel
                color = random_color();
                pixel[i][j][k] = color;
            }
        }
    }

    // Output the pixel art to the console
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            for (k = 0; k < PIXEL_SIZE; k++) {
                // Output a row of pixels
                printf("\x1b[48;2;%d;%d;%dm  \x1b[0m", 
                        pixel[i][j][0], pixel[i][j][1], pixel[i][j][2]);
            }
        }
        printf("\n");       // End the row
    }
}

int main() {
    generate_pixel_art();
    return 0;
}
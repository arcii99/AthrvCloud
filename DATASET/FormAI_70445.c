//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

void generate_pixel_art(int art[HEIGHT][WIDTH]) {
    int i, j, color, shape;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the pixel art
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            // Randomly choose the color and shape of the pixel
            color = rand() % 4;
            shape = rand() % 4;
            
            // Set the pixel's value based on its color and shape
            if (color == 0) {
                // Red
                if (shape == 0) {
                    art[i][j] = 0xff0000; // Square
                } else if (shape == 1) {
                    art[i][j] = 0xff0000; // Circle
                } else if (shape == 2) {
                    art[i][j] = 0xff0000; // Triangle
                } else {
                    art[i][j] = 0xff0000; // Diamond
                }
            } else if (color == 1) {
                // Green
                if (shape == 0) {
                    art[i][j] = 0x00ff00; // Square
                } else if (shape == 1) {
                    art[i][j] = 0x00ff00; // Circle
                } else if (shape == 2) {
                    art[i][j] = 0x00ff00; // Triangle
                } else {
                    art[i][j] = 0x00ff00; // Diamond
                }
            } else if (color == 2) {
                // Blue
                if (shape == 0) {
                    art[i][j] = 0x0000ff; // Square
                } else if (shape == 1) {
                    art[i][j] = 0x0000ff; // Circle
                } else if (shape == 2) {
                    art[i][j] = 0x0000ff; // Triangle
                } else {
                    art[i][j] = 0x0000ff; // Diamond
                }
            } else {
                // Yellow
                if (shape == 0) {
                    art[i][j] = 0xffff00; // Square
                } else if (shape == 1) {
                    art[i][j] = 0xffff00; // Circle
                } else if (shape == 2) {
                    art[i][j] = 0xffff00; // Triangle
                } else {
                    art[i][j] = 0xffff00; // Diamond
                }
            }
        }
    }
}

void draw_pixel_art(int art[HEIGHT][WIDTH]) {
    int i, j;
    
    // Draw the pixel art
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("#%06x ", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int pixel_art[HEIGHT][WIDTH];
    
    // Generate the pixel art
    generate_pixel_art(pixel_art);
    
    // Draw the pixel art
    draw_pixel_art(pixel_art);
    
    return 0;
}
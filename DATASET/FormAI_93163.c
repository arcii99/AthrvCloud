//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: futuristic
// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define global variables
#define WIDTH 80
#define HEIGHT 30
char canvas[WIDTH][HEIGHT];

// Define function to draw pixels
void draw_pixel(int x, int y, char color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    canvas[x][y] = color;
}

// Define function to print the canvas
void print_canvas() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(canvas[x][y]);
        }
        putchar('\n');
    }
}

// Define function to initialize the canvas
void init_canvas() {
    memset(canvas, ' ', WIDTH * HEIGHT);
}

// Define function to generate pixel art
void generate_pixel_art() {
    // Define colors
    char colors[] = { 'R', 'G', 'B', 'Y', 'P', 'O' };
    int num_colors = sizeof(colors) / sizeof(colors[0]);

    // Generate random pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char color = colors[rand() % num_colors];
            draw_pixel(x, y, color);
        }
    }
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize canvas
    init_canvas();

    // Generate pixel art
    generate_pixel_art();

    // Print canvas
    print_canvas();

    return 0;
}
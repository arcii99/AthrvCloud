//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void generate_pixel_art(int pixels[WIDTH][HEIGHT]) {
    // Set random seed
    srand(time(NULL));
    
    // Fill pixels with random values
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[x][y] = rand() % 2;
        }
    }
}

void print_pixel_art(int pixels[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", (pixels[x][y] == 1) ? '*' : ' ');
        }
        printf("\n");
    }
}

int main() {
    // Initialize pixel array
    int pixels[WIDTH][HEIGHT];

    // Generate pixel art and print it
    generate_pixel_art(pixels);
    print_pixel_art(pixels);

    return 0;
}
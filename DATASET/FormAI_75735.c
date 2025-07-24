//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 255

// Function to generate random numbers between 0 and MAX_COLOR
int random_color() {
    return rand()%(MAX_COLOR+1);
}

// Function to generate random pixel art
void create_pixel_art(int pixels[WIDTH][HEIGHT][3]) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            pixels[i][j][0] = random_color(); // Red
            pixels[i][j][1] = random_color(); // Green
            pixels[i][j][2] = random_color(); // Blue
        }
    }
}

// Function to print the pixel art
void print_pixel_art(int pixels[WIDTH][HEIGHT][3]) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("(%d %d %d) ", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create and print pixel art
    int pixels[WIDTH][HEIGHT][3];
    create_pixel_art(pixels);
    print_pixel_art(pixels);

    return 0;
}
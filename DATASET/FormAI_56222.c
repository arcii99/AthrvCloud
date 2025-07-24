//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the grid
#define WIDTH 40
#define HEIGHT 20

// Define the size of the pixel
#define PIXEL_SIZE 2

// Define the probability of a pixel being colored (0-100)
#define DENSITY 30

// Define the color codes of the pixels
#define BLACK 0
#define WHITE 1

// Function that generates a random number
int random_int(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

// Function that prints the pixel grid
void print_grid(int grid[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == WHITE) {
                // Print a white pixel
                for (int k = 0; k < PIXEL_SIZE; k++) {
                    for (int l = 0; l < PIXEL_SIZE; l++) {
                        printf("#");
                    }
                }
            } else {
                // Print a black pixel
                for (int k = 0; k < PIXEL_SIZE; k++) {
                    for (int l = 0; l < PIXEL_SIZE; l++) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}

// Main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the grid with black pixels
    int grid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = BLACK;
        }
    }

    // Color randomly selected pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int probability = random_int(0, 100);
            if (probability < DENSITY) {
                grid[i][j] = WHITE;
            }
        }
    }

    // Print the pixel art
    print_grid(grid);

    return 0;
}
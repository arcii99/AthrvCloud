//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
// Donald Knuth style Pixel Art Generator Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for pixel grid size and color options
#define GRID_SIZE 10
#define COLOR_OPTIONS 4

// Define a struct for a pixel that contains its color
typedef struct Pixel {
    char color;
} Pixel;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the pixel grid
    Pixel grid[GRID_SIZE][GRID_SIZE];

    // Fill the grid with random colors
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int random_color = rand() % COLOR_OPTIONS;
            switch (random_color) {
                case 0:
                    grid[i][j].color = 'R'; // Red
                    break;
                case 1:
                    grid[i][j].color = 'G'; // Green
                    break;
                case 2:
                    grid[i][j].color = 'B'; // Blue
                    break;
                case 3:
                    grid[i][j].color = 'Y'; // Yellow
                    break;
            }
        }
    }

    // Print the pixel grid
    printf("Pixel Art:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j].color);
        }
        printf("\n");
    }

    return 0;
}
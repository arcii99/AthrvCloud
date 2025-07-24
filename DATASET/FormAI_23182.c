//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the pixel art
#define WIDTH 10
#define HEIGHT 10

int main() {
    // Initialize the random seed
    srand(time(NULL));
    
    // Define the color palette
    char colors[] = {' ', '.', ',', '-', '~', ':', ';', '=', '!', '*', '#', '%', '@'};
    int num_of_colors = sizeof(colors) / sizeof(char);
    
    // Create a 2D array to store the pixel art
    char pixels[HEIGHT][WIDTH];
    
    // Fill the array with random colors from the palette
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int rand_index = rand() % num_of_colors;
            pixels[i][j] = colors[rand_index];
        }
    }
    
    // Print the pixel art to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
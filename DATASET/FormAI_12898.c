//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the size of the canvas
#define WIDTH 50
#define HEIGHT 20

// Define the color codes for making pixel art
#define WHITE "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Define an array of color codes for ease of use
const char* colors[] = {WHITE, BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};

// Define the pixel art grid
int art_grid[HEIGHT][WIDTH];

// Define the function to randomly generate pixel art
void generate_art() {
    int i, j, color_index;
    srand(time(NULL));  // Seed the random number generator with the current time
    
    // Loop through each pixel in the grid
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            color_index = rand() % 8;  // Generate a random color index from the colors array
            art_grid[i][j] = color_index;  // Set the color of the pixel
        }
    }
}

// Define the function to print the pixel art
void print_art() {
    int i, j, color_index;

    // Loop through each pixel in the grid
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            color_index = art_grid[i][j];  // Get the color of the pixel from the grid
            printf("%s█", colors[color_index]);  // Print the pixel with the corresponding color code
        }
        printf("%s\n", WHITE);  // Print a new line and reset the color code to white
    }
}

// Define the main function
int main() {
    generate_art();  // Generate the pixel art
    print_art();  // Print the pixel art
    return 0;
}
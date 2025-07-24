//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// Function to draw a square given the x, y coordinates of the top-left corner and the length of the sides
void draw_square(int x, int y, int length) {
    printf("Drawing square at (%d, %d) with length %d\n", x, y, length);
    // Code to actually draw the square would go here
}

int main() {
    // Initialize variables
    int num_squares = 10; // Number of squares in the spiral
    int square_length = 50; // Length of each square's side
    int x = 0; // Starting x-coordinate
    int y = 0; // Starting y-coordinate
    double angle = 0; // Starting angle in radians
    int i;

    // Loop through all the squares in the spiral
    for (i = 0; i < num_squares; i++) {
        // Calculate the coordinates of the next square based on the angle and current coordinates
        int next_x = x + (int)(square_length * cos(angle));
        int next_y = y + (int)(square_length * sin(angle));
        // Draw the square at the new coordinates
        draw_square(x, y, square_length);
        // Update the current coordinates to the next square's coordinates
        x = next_x;
        y = next_y;
        // Calculate the new angle for the next square
        angle += PI / 2;
    }

    return 0;
}
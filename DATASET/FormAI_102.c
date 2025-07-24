//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
#include <math.h>

// Define the number of rows and columns in the spiral
#define SIZE 16

int main() {
    
    int spiral[SIZE][SIZE]; // Create a 2D array to hold the spiral
    int current = 1; // Start with 1
    int x = SIZE / 2; // Start in the middle column
    int y = SIZE / 2; // Start in the middle row
    int xDir = 1; // Start moving to the right
    int yDir = 0; // Do not move up or down yet
    
    // Fill the spiral with 0s initially
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            spiral[i][j] = 0;
        }
    }
    
    // Loop through the spiral and fill it with the Fibonacci sequence
    while (current <= SIZE * SIZE) {
        spiral[y][x] = current;
        
        // Check if we need to change direction
        if (x + xDir < 0 || y + yDir < 0 || x + xDir >= SIZE || y + yDir >= SIZE || spiral[y + yDir][x + xDir] != 0) {
            int temp = yDir;
            yDir = xDir;
            xDir = -temp; // Flip the direction
            
        }
        
        // Move to the next position
        x += xDir;
        y += yDir;
        current++;
    }
    
    // Print out the spiral
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", spiral[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
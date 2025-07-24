//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50

int main() {
    // Set up random seed
    srand(time(NULL));
    
    // Initialize pixel art matrix
    int pixelArt[HEIGHT][WIDTH];
    
    // Generate random pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = rand() % 2;
        }
    }
    
    // Print pixel art
    printf("Pixel Art:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", pixelArt[i][j]);
        }
        printf("\n");
    }
    
    // Count connected pixels
    int numConnected = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixelArt[i][j] == 1) {
                numConnected++;
                // Perform depth-first search to find all connected pixels
                int stack[HEIGHT * WIDTH][2];
                int stackPtr = 0;
                stack[stackPtr][0] = i;
                stack[stackPtr][1] = j;
                pixelArt[i][j] = 2;
                while (stackPtr >= 0) {
                    int row = stack[stackPtr][0];
                    int col = stack[stackPtr][1];
                    stackPtr--;
                    // Check all adjacent pixels
                    if (row > 0 && pixelArt[row-1][col] == 1) {
                        stackPtr++;
                        stack[stackPtr][0] = row - 1;
                        stack[stackPtr][1] = col;
                        pixelArt[row-1][col] = 2;
                    }
                    if (row < HEIGHT-1 && pixelArt[row+1][col] == 1) {
                        stackPtr++;
                        stack[stackPtr][0] = row + 1;
                        stack[stackPtr][1] = col;
                        pixelArt[row+1][col] = 2;
                    }
                    if (col > 0 && pixelArt[row][col-1] == 1) {
                        stackPtr++;
                        stack[stackPtr][0] = row;
                        stack[stackPtr][1] = col - 1;
                        pixelArt[row][col-1] = 2;
                    }
                    if (col < WIDTH-1 && pixelArt[row][col+1] == 1) {
                        stackPtr++;
                        stack[stackPtr][0] = row;
                        stack[stackPtr][1] = col + 1;
                        pixelArt[row][col+1] = 2;
                    }
                }
            }
        }
    }
    
    // Print number of connected pixels
    printf("Number of Connected Pixels: %d\n", numConnected);
    
    return 0;
}
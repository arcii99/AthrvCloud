//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

char pixelArt[HEIGHT][WIDTH];

void generatePixelArt() {
    int i, j;
    
    // Seed random number generator
    srand(time(NULL));
    
    // Generate random pixel art
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = rand() % 2 == 0 ? '#' : ' ';
        }
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    
    if (row > 0 && pixelArt[row - 1][col] == '#') count++; // Top
    if (row < HEIGHT - 1 && pixelArt[row + 1][col] == '#') count++; // Bottom
    if (col > 0 && pixelArt[row][col - 1] == '#') count++; // Left
    if (col < WIDTH - 1 && pixelArt[row][col + 1] == '#') count++; // Right
    
    return count;
}

void applyRules(int row, int col) {
    int count = countNeighbors(row, col);
    
    if (pixelArt[row][col] == '#' && count < 2) {
        pixelArt[row][col] = ' ';
    }
    else if (pixelArt[row][col] == '#' && (count == 2 || count == 3)) {
        pixelArt[row][col] = '#';
    }
    else if (pixelArt[row][col] == '#' && count > 3) {
        pixelArt[row][col] = ' ';
    }
    else if (pixelArt[row][col] == ' ' && count == 3) {
        pixelArt[row][col] = '#';
    }
}

void animatePixelArt() {
    int i, j;
    bool hasChanged;
    
    do {
        hasChanged = false;
        
        // Apply the rules of Conway's Game of Life
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                applyRules(i, j);
                if (pixelArt[i][j] != ' ') hasChanged = true;
            }
        }
        
        // Print the current state of the pixel art
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                printf("%c", pixelArt[i][j]);
            }
            printf("\n");
        }
        
        // Wait for a short period of time before continuing
        sleep(1);
        system("clear");
    } while (hasChanged);
}

int main() {
    generatePixelArt();
    animatePixelArt();
    
    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>

// Function to print the pixel art
void printPixelArt(char pixelArt[][5], int width, int height) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixelArt[5][5] = {
        {'#', '#', '#', '#', '#'},
        {'#', '#', '@', '#', '#'},
        {'#', '@', '@', '@', '#'},
        {'#', '#', '@', '#', '#'},
        {'#', '#', '#', '#', '#'},
    };

    int width = 5;
    int height = 5;
    
    // Print the pixel art
    printPixelArt(pixelArt, width, height);
    
    return 0;
}
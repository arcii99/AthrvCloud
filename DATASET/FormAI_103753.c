//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: standalone
#include <stdio.h>

#define ROWS 10
#define COLS 10

int main() {
    char pixels[ROWS][COLS];
    
    // Initialize pixels to blank space
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            pixels[i][j] = ' ';
        }
    }
    
    // Set pixels to form a 'C' shape
    pixels[0][0] = 'X';
    pixels[0][1] = 'X';
    pixels[0][2] = 'X';
    pixels[1][0] = 'X';
    pixels[2][0] = 'X';
    pixels[2][1] = 'X';
    pixels[2][2] = 'X';
    
    // Display pixel art
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
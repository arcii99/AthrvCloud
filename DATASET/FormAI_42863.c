//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>

#define ROWS 10  // Number of rows in the pixel art
#define COLS 10  // Number of columns in the pixel art

// Define the pixel art using a multi-dimensional array
int pixels[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 }
};

// A function to output the pixel art to the console
void printPixelArt() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (pixels[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Output the pixel art to the console
    printPixelArt();
    
    return 0;
}
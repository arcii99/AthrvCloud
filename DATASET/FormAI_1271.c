//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define color codes
#define BLACK "\u2588\u2588"
#define GRAY "\u2593\u2593"
#define WHITE "\u2591\u2591"

void printPixelArt(int pixels[][10], int rows, int cols);

int main() {
    int pixels[10][10]; // 10x10 pixel art

    // Seed the random number generator
    srand(time(NULL));

    // Generate random pixel colors
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int colorRand = rand() % 3;
            pixels[i][j] = colorRand;
        }
    }

    // Display pixel art
    printPixelArt(pixels, 10, 10);

    return 0;
}

void printPixelArt(int pixels[][10], int rows, int cols) {
    // Iterate through each row of pixels
    for (int i = 0; i < rows; i++) {
        // Iterate through each column of pixels in the row
        for (int j = 0; j < cols; j++) {
            // Print the appropriate color code based on the pixel's value
            if (pixels[i][j] == 0) {
                printf(BLACK);
            } else if (pixels[i][j] == 1) {
                printf(GRAY);
            } else {
                printf(WHITE);
            }

            // Add a space between pixels for clarity
            printf(" ");
        }

        // Move to the next row of pixels
        printf("\n");
    }
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate pixel art
void generatePixelArt(int rows, int cols) {
    int pixels[rows][cols];

    // Fill pixels array randomly
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pixels[i][j] = rand() % 2;
        }
    }

    // Print pixels array as pixel art
    printf("Your unique pixel art:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
    int rows, cols;

    // Get dimensions of pixel art
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Ensure dimensions meet minimum requirements
    if (rows < 5 || cols < 5) {
        printf("Error: Dimensions must be at least 5x5.\n");
        return 1;
    }

    generatePixelArt(rows, cols);

    return 0;
}
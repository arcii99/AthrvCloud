//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the pixel art for a given color
void printPixel(char color, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", color);
        }
        printf("\n");
    }
}

int main() {
    // Set seed for randomization
    srand(time(NULL));

    // Define array of pixel colors
    char colors[] = {'R', 'G', 'B', 'Y', 'O', 'P'};

    // Define variables for size and number of pixels
    int size, numPixels;

    // Prompt user for input
    printf("Enter a size for the pixels: ");
    scanf("%d", &size);
    printf("Enter the number of pixels you want to generate: ");
    scanf("%d", &numPixels);

    // Generate random pixels
    for (int i = 0; i < numPixels; i++) {
        int randIndex = rand() % 6; // Random index between 0 and 5
        char randColor = colors[randIndex];
        printPixel(randColor, size);
        printf("\n");
    }

    return 0;
}
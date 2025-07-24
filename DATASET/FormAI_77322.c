//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random pixel art
void generatePixelArt() {
    int width, height;
    printf("Enter the width and height of the pixel art: ");
    scanf("%d %d", &width, &height);
    char pixelArt[height][width];

    // Generate random characters for pixel art
    char charArr[6] = {'@', '#', '*', '.', '+', '-'};
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixelArt[i][j] = charArr[rand() % 6];
        }
    }

    // Print the pixel art
    printf("\nPixel Art:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    generatePixelArt();
    return 0;
}
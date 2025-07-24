//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int width, height;
    printf("Enter the width of the canvas: ");
    scanf("%d", &width);
    printf("Enter the height of the canvas: ");
    scanf("%d", &height);

    srand(time(0)); // Seed the random number generator with current time
    char pixelArt[height][width];

    // Generate random pixel art
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int randomNum = rand() % 10; // Generate a random number between 0-9
            if (randomNum < 5) {
                pixelArt[i][j] = '*'; // Approximately half the time, print a *
            } else {
                pixelArt[i][j] = ' '; // The other half of the time, print a space
            }
        }
    }

    // Print the pixel art to the console
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            printf("%c", pixelArt[i][j]);
        }
        printf("\n"); // Move to the next line after printing a row of pixels
    }

    return 0;
}
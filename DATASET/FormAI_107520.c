//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the random seed to the current time
    srand(time(NULL));

    // Define the width and height of the pixel art
    const int WIDTH = 10;
    const int HEIGHT = 10;

    // Create the 2D array to hold the pixel values
    int pixels[HEIGHT][WIDTH];

    // Generate random pixel values ranging from 0 to 255
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 256;
        }
    }

    // Print the pixel values as a pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixels[i][j] < 128) {
                // Use a # for dark pixels
                printf("# ");
            } else {
                // Use a . for light pixels
                printf(". ");
            }
        }
        printf("\n");
    }

    // Exit the program with success status
    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50 // Width of the pixel art
#define HEIGHT 20 // Height of the pixel art

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Two-dimensional array to hold the pixel art
    char pixelArt[HEIGHT][WIDTH+1]; // The +1 is for the null terminator character at the end of each row

    // Populate the array with random characters
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            // Randomly choose a character from our list of options
            char options[] = {' ', '.', '*', '+', '-', '=', '#', '%', '&', '$', '@'};
            int numOptions = sizeof(options) / sizeof(options[0]);
            char randomChar = options[rand() % numOptions];

            // Add the randomly chosen character to the pixel art array
            pixelArt[row][col] = randomChar;
        }
        pixelArt[row][WIDTH] = '\0'; // Add the null terminator character to the end of the row
    }

    // Print the pixel art array to the console
    for (int row = 0; row < HEIGHT; row++) {
        printf("%s\n", pixelArt[row]);
    }

    return 0;
}
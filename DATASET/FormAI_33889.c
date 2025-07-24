//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
/* Pixel Art Generator in a Romeo and Juliet Style */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between min and max (inclusive) */
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    /* Seed the random number generator with the current time */
    srand(time(NULL));

    /* Set the dimensions of the pixel art */
    const int width = 20;
    const int height = 20;

    /* Set the ASCII characters to use for the pixel art */
    const char pixels[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    /* Initialize the pixel art array to all zeros */
    int art[height][width];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            art[row][col] = 0;
        }
    }

    /* Generate pixel art in a Romeo and Juliet style */
    for (int i = 0; i < 100; i++) {
        int row1 = rand_int(0, height - 1);
        int col1 = rand_int(0, width - 1);
        int row2 = rand_int(0, height - 1);
        int col2 = rand_int(0, width - 1);

        int pixel = rand_int(0, 9);

        art[row1][col1] = pixel;
        art[row2][col2] = pixel;
    }

    /* Print the pixel art to the console */
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%c", pixels[art[row][col]]);
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define CONSTANTS for the dimensions of the art */
#define WIDTH 50
#define HEIGHT 20

/* Define CONSTANTS for the color values */
#define BLACK 0
#define WHITE 1

/* Generate random numbers between 0 - 1 */
#define RAND ((double)rand() / (double)RAND_MAX)

/* Main function */
int main(void) {

    /* Seed the random number generator */
    srand(time(NULL));

    /* Define the Pixel Art array */
    int art[HEIGHT][WIDTH];

    /* Fill the array with random color values */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (RAND > 0.5) {
                art[i][j] = WHITE;
            } else {
                art[i][j] = BLACK;
            }
        }
    }

    /* Print the Pixel Art on the console */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (art[i][j] == WHITE) {
                printf("O");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    /* End the program */
    return EXIT_SUCCESS;
}
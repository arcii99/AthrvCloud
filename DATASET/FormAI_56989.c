//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int i, j, k;
    char canvas[WIDTH][HEIGHT];

    // Seed random number generator
    srand(time(NULL));

    // Initialize canvas with spaces
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Generate random pixels
    for (k = 0; k < 500; k++) {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
        canvas[i][j] = 'X';
    }

    // Print canvas
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }

    return 0;
}
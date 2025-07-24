//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants for the size and color values of the pixel art */
#define WIDTH 20 
#define HEIGHT 20
#define COLORS 5 

/* Function to generate random pixel art */
void generatePixelArt(int** art) {
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            art[i][j] = rand() % COLORS;
        }
    }
}

/* Function to print the pixel art to the console */
void printPixelArt(int** art) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%d", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /* Allocate memory for the pixel art */
    int** art = (int**)malloc(HEIGHT * sizeof(int*));
    for(int i = 0; i < HEIGHT; i++) {
        art[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    /* Generate and print the pixel art */
    generatePixelArt(art);
    printPixelArt(art);

    /* Free memory for the pixel art */
    for(int i = 0; i < HEIGHT; i++) {
        free(art[i]);
    }
    free(art);

    return 0;
}
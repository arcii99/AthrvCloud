//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int pixelArt[WIDTH][HEIGHT];

/*Function to generate random pixel art*/
void generatePixelArt() {
    int i, j;
    /*Setting the random seed*/
    srand(time(NULL));
    /*Filling each pixel with random values*/
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            pixelArt[i][j] = rand() % 2;
        }
    }
}

/*Function to print the generated pixel art*/
void printPixelArt() {
    int i, j;
    /*Printing the pixel art*/
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            printf("%d ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /*Generating the pixel art*/
    generatePixelArt();
    /*Printing the pixel art*/
    printPixelArt();
    return 0;
}
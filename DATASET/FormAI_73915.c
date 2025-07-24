//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15

int main() {
    srand(time(0)); // seed the random number generator

    int pixels[HEIGHT][WIDTH];

    // generate random pixel values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 2; // either 0 or 1
        }
    }

    // print the pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixels[i][j] == 0) {
                printf(" "); // print a space for a black pixel
            } else {
                printf("#"); // print a pound sign for a white pixel
            }
        }
        printf("\n"); // move to the next row
    }

    return 0; // terminate the program
}
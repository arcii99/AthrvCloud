//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

int main() {
    char pixel[HEIGHT][WIDTH];
    srand(time(NULL)); // seed the random generator with current time

    // initialize the pixel array with random values
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int r = rand() % 2; // generate either 0 or 1 randomly
            pixel[i][j] = r == 0 ? ' ' : '*'; // if r is 0, set pixel to ' ', otherwise set to '*'
        }
    }

    // print the pixel art
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", pixel[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the width and height of our canvas
#define WIDTH 100
#define HEIGHT 30

// define the characters we'll use to create our pixel art
char pixels[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int main() {
    // seed the random number generator
    srand(time(NULL));

    // create a 2D array of characters to represent our canvas
    char canvas[HEIGHT][WIDTH];

    // loop through each row of the canvas
    for (int y = 0; y < HEIGHT; y++) {
        // loop through each column of the canvas
        for (int x = 0; x < WIDTH; x++) {
            // choose a random pixel character to fill this cell
            int index = rand() % sizeof(pixels);
            canvas[y][x] = pixels[index];
        }
    }

    // loop through each row of the canvas
    for (int y = 0; y < HEIGHT; y++) {
        // loop through each column of the canvas
        for (int x = 0; x < WIDTH; x++) {
            // output the character in this cell to the console
            printf("%c", canvas[y][x]);
        }
        // move to the next line
        printf("\n");
    }

    // exit the program
    return 0;
}
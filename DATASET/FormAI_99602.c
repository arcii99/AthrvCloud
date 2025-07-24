//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// define constants for width and height of the pixel art
#define WIDTH 10
#define HEIGHT 10

// define the pixel art array
char pixel_art[HEIGHT][WIDTH];

// function to randomly generate a pixel art
void generate_pixel_art() {
    // seed the random number generator
    srand(time(NULL));

    // loop through each pixel
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // generate a random number between 0 and 2
            int random_num = rand() % 3;

            // set the value of the pixel based on the random number
            switch (random_num) {
                case 0:
                    pixel_art[i][j] = ' ';
                    break;
                case 1:
                    pixel_art[i][j] = '.';
                    break;
                case 2:
                    pixel_art[i][j] = '#';
                    break;
            }
        }
    }
}

// function to print the pixel art to the console
void print_pixel_art() {
    // loop through each pixel and print it to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixel_art[i][j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    // generate the pixel art
    generate_pixel_art();

    // print the pixel art to the console
    print_pixel_art();

    return 0;
}
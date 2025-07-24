//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define PIXEL '#'

void generate_art(char art[][WIDTH]);
void print_art(char art[][WIDTH]);

int main(void) {
    char art[HEIGHT][WIDTH];
    srand(time(NULL)); // Seed random number generator based on time

    generate_art(art);
    print_art(art);

    return 0;
}

// Function to generate the pixel art
void generate_art(char art[][WIDTH]) {
    // Set all elements to blank spaces
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            art[i][j] = ' ';
        }
    }

    // Randomly generate pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0) {
                art[i][j] = PIXEL;
            }
        }
    }
}

// Function to print out the pixel art
void print_art(char art[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", art[i][j]);
        }
        printf("\n");
    }
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    // define the size of the art
    const int WIDTH = 8;
    const int HEIGHT = 8;

    // create the art
    char art[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // randomly choose a character to represent the pixel
            int rand_num = rand() % 3;
            switch (rand_num) {
                case 0:
                    art[y][x] = 'O';
                    break;
                case 1:
                    art[y][x] = 'X';
                    break;
                case 2:
                    art[y][x] = '#';
                    break;
            }
        }
    }

    // print the art to the console
    printf("Here's your unique pixel art:\n\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", art[y][x]);
        }
        printf("\n");
    }

    return 0;
}
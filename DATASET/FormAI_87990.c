//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8 // Change this value to increase or decrease the size of the pixel art


int main(void) {
    int row, col, num;
    char pixel[SIZE][SIZE]; // 2D array to store the pixel art

    // Randomly assign values to each element of pixel array
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            num = rand() % 2; // Generate random number 0 or 1
            if (num == 0) {
                pixel[row][col] = ' ';
            } else {
                pixel[row][col] = 'X';
            }
        }
    }

    // Print out pixel art in console
    printf("\n");
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            printf("%c", pixel[row][col]);
        }
        printf("\n");
    }

    return 0;
}
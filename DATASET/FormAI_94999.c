//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define PIXEL_SIZE 5

int main(void) {
    char image[ROWS][COLS];
    int colorCode;
    srand(time(NULL));

    // Fill the image with random color codes
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            colorCode = rand() % 2; // 0 or 1
            image[r][c] = colorCode ? 'X' : 'O'; // 'X' for black pixels and 'O' for white pixels
        }
    }

    // Draw the image
    for (int r = 0; r < ROWS; r++) {
        for (int i = 0; i < PIXEL_SIZE; i++) {
            for (int c = 0; c < COLS; c++) {
                for (int j = 0; j < PIXEL_SIZE; j++) {
                    printf("%c", image[r][c]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
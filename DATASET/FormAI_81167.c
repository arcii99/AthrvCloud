//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int width = 50;
    int height = 50;

    int pixel_board[width][height];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            pixel_board[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pixel_board[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
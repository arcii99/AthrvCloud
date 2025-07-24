//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main() {
    int row, col, height, width;
    height = width = 7;

    for (row = 1; row <= height; row++) {
        for (col = 1; col <= width; col++) {
            if ((row == 1 && col > 1 && col < height) || 
                (col == 1 && row > 1 && row < height) || 
                (row == height && col > 1 && col < height)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (row = 1; row <= height; row++) {
        for (col = 1; col <= width; col++) {
            if (((row == 1 || row == height) && col > height && col < width) || 
                (col == height && row != 1 && row != height)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
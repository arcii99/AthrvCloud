//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
    int height = 15;
    int width = 15;

    char matrix[height][width];

    // Fill matrix with space characters
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';
        }
    }

    // Draw C pattern
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            if ((i == 1 && (j >= 2 && j <= 6)) || 
                (j == 2 && (i >= 2 && i <= 7)) || 
                (i == 7 && (j >= 2 && j <= 6)) ||
                (j == 6 && (i >= 3 && i <= 6))) {
                matrix[i][j] = '#';
            }
        }
    }

    // Print matrix
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] != '#') {
                // Randomly print either "·" or space character
                if (rand() % 2 == 0) {
                    printf(" ");
                } else {
                    printf("·");
                }
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_rows = 7, num_cols = 7;
    char grid[num_rows][num_cols];

    // fill the grid with spaces
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            grid[i][j] = ' ';
        }
    }

    // print initial grid
    printf("\nInitial grid:\n\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    // add pattern to grid
    for (int i = 1; i < num_rows-1; i++) {
        for (int j = 1; j < num_cols-1; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                grid[i][j] = 'C';
            }
            else if (i % 2 == 1 && j % 2 == 1) {
                grid[i][j] = 'C';
            }
        }
    }

    // print updated grid
    printf("\nPattern in grid:\n\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
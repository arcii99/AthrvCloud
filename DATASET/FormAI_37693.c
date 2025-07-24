//FormAI DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 20;
    int board[size][size];
    int i, j, k, count, alive;

    // Initialize board
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Run generations indefinitely
    while (1) {
        // Print board
        system("clear");
        printf("THE GAME OF LIFE\n\n");
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (board[i][j] == 1) {
                    printf("O");
                }
                else {
                    printf("-");
                }
            }
            printf("\n");
        }

        // Apply rules of Life
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                count = 0;

                // Check surrounding cells
                for (k = -1; k <= 1; k++) {
                    for (alive = -1; alive <= 1; alive++) {

                        // Ignore current cell
                        if (k == 0 && alive == 0) {
                            continue;
                        }

                        // Check boundaries and count alive cells
                        if (i + k >= 0 && i + k < size &&
                            j + alive >= 0 && j + alive < size &&
                            board[i + k][j + alive] == 1) {
                            count++;
                        }
                    }
                }

                // Apply rules
                if (board[i][j] == 1 && count < 2) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 1 && count > 3) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 1;
                }
            }
        }

        // Slow down for dramatic effect
        for (k = 0; k < 50000000; k++) {}
    }

    return 0;
}
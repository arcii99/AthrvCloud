//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Recursive function to generate and print Fractal using Conway's Game of Life rules
 */
void conways_game_of_life(int prev[][512], int curr[][512], int x, int y, int level, int size) {
    int i, j, m, n, count, next;

    // Base case
    if (level >= size)
        return;

    // Clear current level
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            curr[i][j] = 0;
        }
    }

    // Apply Conway's Game of Life rules
    for (i = 1; i < size - 1; i++) {
        for (j = 1; j < size - 1; j++) {
            count = 0;
            for (m = i - 1; m <= i + 1; m++) {
                for (n = j - 1; n <= j + 1; n++) {
                    if (m != i || n != j) {
                        count += prev[m][n];
                    }
                }
            }
            if (prev[i][j] == 0) {
                if (count == 3) {
                    curr[i][j] = 1;
                }
            } else {
                if (count == 2 || count == 3) {
                    curr[i][j] = 1;
                }
            }
        }
    }

    // Print current level
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (curr[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Recursive call on smaller level
    next = (int)pow(2, level+1);
    conways_game_of_life(curr, prev, x-next/2, y-next/2, level+1, size);
    conways_game_of_life(curr, prev, x+next/2, y-next/2, level+1, size);
    conways_game_of_life(curr, prev, x-next/2, y+next/2, level+1, size);
    conways_game_of_life(curr, prev, x+next/2, y+next/2, level+1, size);
}

/*
 * Main function to generate Fractal using Conway's Game of Life rules
 */
int main()
{
    int prev[512][512], curr[512][512];
    int size = 512, level = 0;
    int i, j, x, y, count;
    
    // Initialize seed for Game of Life
    srand(42);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            prev[i][j] = rand() % 2;
        }
    }

    // Print initial state of Game of Life
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (prev[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Choose center point for Fractal
    x = size/2;
    y = size/2;

    // Generate Fractal using Conway's Game of Life rules
    conways_game_of_life(prev, curr, x, y, level, size);

    return 0;
}
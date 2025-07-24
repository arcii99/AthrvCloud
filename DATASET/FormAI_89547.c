//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main() {
    // initialize random seed
    srand(time(NULL));

    // initialize the map
    int map[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                map[i][j] = 1; // border is always blocked
            } else {
                map[i][j] = (rand() % 100 < 70) ? 1 : 0; // randomly block some cells
            }
        }
    }

    // print the initial map
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // percolation simulation
    int perc = 0;
    int count = 0;
    while (perc == 0) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (map[r][c] == 0) {
            map[r][c] = 1;
            count = 0;
            for (int j = 1; j < COLS - 1; j++) {
                if (map[1][j] == 0 && map[2][j] == 1) {
                    perc = 1;
                    break;
                }
            }
        }

        // print the map
        system("cls"); // clear the console (Windows specific)
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (map[i][j] == 1) {
                    printf("██");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }

        // delay to make the simulation visible
        for (int i = 0; i < 100000000; i++);
        count++;
        if (count >= ROWS * COLS) {
            perc = -1; // no percolation
            break;
        }
    }

    // print the result
    if (perc == 1) {
        printf("Percolation achieved after %d iterations!\n", count);
    } else {
        printf("No percolation achieved after %d iterations!\n", count);
    }

    return 0;
}
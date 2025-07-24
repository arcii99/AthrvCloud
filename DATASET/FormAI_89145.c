//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MINE_PROB 0.15

int count_adjacent_mines(int row, int col, int minefield[ROWS][COLS]) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int r = row + i;
            int c = col + j;
            if(r >= 0 && r < ROWS && c >= 0 && c < COLS && minefield[r][c] == -1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(NULL));
    int minefield[ROWS][COLS];

    // initialize minefield
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if((double)rand() / RAND_MAX < MINE_PROB) {
                minefield[i][j] = -1;
            } else {
                minefield[i][j] = 0;
            }
        }
    }

    // calculate counts of adjacent mines
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(minefield[i][j] == -1) {
                continue;
            }
            minefield[i][j] = count_adjacent_mines(i, j, minefield);
        }
    }

    // print minefield
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(minefield[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", minefield[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
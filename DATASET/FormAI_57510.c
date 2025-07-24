//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define BARRIER_PROB 0.6
#define MAX_GROUPS 50

/* Function to check if site is open */
bool isOpen(int row, int col, bool grid[ROWS][COLS]) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    return grid[row][col];
}

/* Function to get index of a site */
int getIndex(int row, int col) {
    return row * COLS + col;
}

/* Function to connect two open sites */
void connect(int row1, int col1, int row2, int col2, int groups[MAX_GROUPS][ROWS*COLS], int groupSizes[MAX_GROUPS], int *groupCount) {
    int index1 = getIndex(row1, col1);
    int index2 = getIndex(row2, col2);
    int group1 = -1, group2 = -1;

    for (int i = 0; i < *groupCount; i++) {
        if (groups[i][index1]) {
            group1 = i;
        }
        if (groups[i][index2]) {
            group2 = i;
        }
    }

    if (-1 == group1 && -1 == group2) {
        groups[*groupCount][index1] = true;
        groups[*groupCount][index2] = true;
        groupSizes[*groupCount] += 2;
        (*groupCount)++;
    } else if (-1 == group1) {
        groups[group2][index1] = true;
        groupSizes[group2]++;
    } else if (-1 == group2) {
        groups[group1][index2] = true;
        groupSizes[group1]++;
    } else if (group1 != group2) {
        for (int i = 0; i < ROWS*COLS; i++) {
            if (groups[group1][i]) {
                groups[group2][i] = true;   
            }
        }
        groupSizes[group2] += groupSizes[group1];
        groupSizes[group1] = 0;
    }
}

/* Main function to simulate percolation */
int main() {
    srand(time(NULL));
    bool grid[ROWS][COLS];
    int groups[MAX_GROUPS][ROWS*COLS] = {0};
    int groupSizes[MAX_GROUPS] = {0};
    int groupCount = 0;

    /* Initialize grid with closed sites */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = false;
        }
    }

    /* Add randomly placed barriers to the grid */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double prob = (double)rand() / (double)RAND_MAX;
            if (prob < BARRIER_PROB) {
                grid[i][j] = true;
            }
        }
    }

    /* Connect open sites in the grid */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!grid[i][j]) {
                continue;
            }
            if (isOpen(i-1, j, grid)) {
                connect(i, j, i-1, j, groups, groupSizes, &groupCount);
            }
            if (isOpen(i+1, j, grid)) {
                connect(i, j, i+1, j, groups, groupSizes, &groupCount);
            }
            if (isOpen(i, j-1, grid)) {
                connect(i, j, i, j-1, groups, groupSizes, &groupCount);
            }
            if (isOpen(i, j+1, grid)) {
                connect(i, j, i, j+1, groups, groupSizes, &groupCount);
            }
        }
    }

    /* Check if grid percolates */
    bool percolates = false;
    for (int i = 0; i < COLS; i++) {
        if (isOpen(0, i, grid) && isOpen(ROWS-1, i, grid)) {
            for (int j = 0; j < groupCount; j++) {
                if (groups[j][getIndex(0, i)] && groups[j][getIndex(ROWS-1, i)]) {
                    percolates = true;
                    break;
                }
            }
        }
        if (percolates) {
            break;
        }
    }

    /* Print grid and results */
    printf("Grid:\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf("[ ]");
            } else {
                printf("[X]");
            }
        }
        printf("\n");
    }
    printf("\n");

    if (percolates) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }

    return 0;
}
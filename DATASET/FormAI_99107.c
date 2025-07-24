//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];

typedef struct {
    int x;
    int y;
} site;

bool is_open(site s) {
    return grid[s.x][s.y] == 1;
}

void open(site s) {
    grid[s.x][s.y] = 1;
}

bool is_full(site s) {
    if (!is_open(s)) {
        return false;
    }
    if (s.x == 0) {
        return true;
    }
    site top = {s.x - 1, s.y};
    site left = {s.x, s.y - 1};
    site right = {s.x, s.y + 1};
    site bottom = {s.x + 1, s.y};
    return is_full(top) || is_full(left) || is_full(right) || is_full(bottom);
}

bool percolates() {
    for (int j = 0; j < COLS; j++) {
        if (is_full((site){ROWS - 1, j})) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    
    // initialize grid to all closed
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
    
    // open random sites
    while (!percolates()) {
        int i = rand() % ROWS;
        int j = rand() % COLS;
        site s = {i, j};
        open(s);
    }
    
    // print the final state of the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
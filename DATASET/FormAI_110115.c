//FormAI DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

bool grid[HEIGHT][WIDTH];

void init_grid() {
    srand(time(NULL));
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    printf("\n");
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            printf("%c", (grid[i][j]) ? 'X' : '-');
        }
        printf("\n");
    }
}

int count_neighbours(int row, int col) {
    int count = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (i == 0 && j == 0) continue;
            int neighbour_row = row + i;
            int neighbour_col = col + j;
            if (neighbour_row >= 0 && neighbour_row < HEIGHT
                && neighbour_col >= 0 && neighbour_col < WIDTH
                && grid[neighbour_row][neighbour_col]) {
                count++;
            }
        }
    }
    return count;
}

void update_grid() {
    bool new_grid[HEIGHT][WIDTH];
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            int neighbours = count_neighbours(i, j);
            if (grid[i][j]) {
                new_grid[i][j] = (neighbours == 2 || neighbours == 3);
            } else {
                new_grid[i][j] = (neighbours == 3);
            }
        }
    }
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    init_grid();
    int generations = 0;
    while (generations < 100) {
        print_grid();
        update_grid();
        generations++;
    }
    return 0;
}
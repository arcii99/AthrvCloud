//FormAI DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int grid[ROWS][COLUMNS];

void generate_grid() {
    srand(time(NULL));
    int row, column;
    for(row = 0; row < ROWS; row++) {
        for(column = 0; column < COLUMNS; column++) {
            grid[row][column] = rand() % 2;
            if(grid[row][column] == 1) {
                printf("\u2588\u2588 ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_grid() {
    int row, column;
    for(row = 0; row < ROWS; row++) {
        for(column = 0; column < COLUMNS; column++) {
            if(grid[row][column] == 1) {
                printf("\u2588\u2588 ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int get_neighbor_count(int row, int column) {
    int count = 0;
    int neighbor_row, neighbor_column;

    for(neighbor_row = row - 1; neighbor_row <= row + 1; neighbor_row++) {
        for(neighbor_column = column - 1; neighbor_column <= column + 1; neighbor_column++) {
            if(neighbor_row < 0 || neighbor_row >= ROWS) {
                continue;
            }
            if(neighbor_column < 0 || neighbor_column >= COLUMNS) {
                continue;
            }
            if(neighbor_row == row && neighbor_column == column) {
                continue;
            }
            if(grid[neighbor_row][neighbor_column] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_grid() {
    int row, column;
    int new_grid[ROWS][COLUMNS];
    for(row = 0; row < ROWS; row++) {
        for(column = 0; column < COLUMNS; column++) {
            int neighbor_count = get_neighbor_count(row, column);
            if(grid[row][column] == 1) {
                if(neighbor_count < 2 || neighbor_count > 3) {
                    new_grid[row][column] = 0;
                } else {
                    new_grid[row][column] = 1;
                }
            } else {
                if(neighbor_count == 3) {
                    new_grid[row][column] = 1;
                } else {
                    new_grid[row][column] = 0;
                }
            }
        }
    }
    for(row = 0; row < ROWS; row++) {
        for(column = 0; column < COLUMNS; column++) {
            grid[row][column] = new_grid[row][column];
        }
    }
}

int main() {
    generate_grid();
    int i;
    for(i = 0; i < 10; i++) {
        printf("\n");
        update_grid();
        print_grid();
        sleep(1);
    }
    return 0;
}
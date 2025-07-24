//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 10
#define COL 10

bool grid[ROW][COL];
bool visited[ROW][COL];

// Function to randomly fill the grid with solid blocks or empty blocks
void fill_grid() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            int rnd = rand() % 100;
            if(rnd < 40) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
}

// DFS Algorithm to find if we can reach bottom of the grid
void dfs(int row, int col) {
    if(row < 0 || row >= ROW || col < 0 || col >= COL || !grid[row][col] || visited[row][col]) {
        return;
    }

    visited[row][col] = true;

    dfs(row-1, col);
    dfs(row+1, col);
    dfs(row, col-1);
    dfs(row, col+1);
}

// Function to check if percolation has occured i.e if we can reach bottom of the grid from top
bool percolation() {
    for(int j = 0; j < COL; j++) {
        if(grid[0][j]) {
            dfs(0, j);
            for(int i = 0; i < ROW; i++) {
                if(visited[i][j]) {
                    return true;
                }
            }
        }
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                visited[i][j] = false;
            }
        }
    }
    return false;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    fill_grid();

    printf("Initial Grid:\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(grid[i][j]) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    if(percolation()) {
        printf("Percolation has occured!\n");
    } else {
        printf("Percolation has not occured.\n");
    }

    return 0;
}
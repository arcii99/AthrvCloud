//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 20
#define COLUMNS 20

char maze[ROWS][COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '#', '.', '#', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool visited[ROWS][COLUMNS];

bool is_valid_location(int row, int col) {
    
    if (maze[row][col] == '#' || visited[row][col]) {
        return false;
    }
    
    return true;
}

bool find_path(int row, int col, int destination_row, int destination_col) {
    
    if (row == destination_row && col == destination_col) {
        return true;
    }
    
    visited[row][col] = true;
    
    if (row > 0 && is_valid_location(row - 1, col)) {
        if (find_path(row - 1, col, destination_row, destination_col)) {
            printf("(%d, %d)\n", row - 1, col);
            return true;
        }
    }
    
    if (row < ROWS - 1 && is_valid_location(row + 1, col)) {
        if (find_path(row + 1, col, destination_row, destination_col)) {
            printf("(%d, %d)\n", row + 1, col);
            return true;
        }
    }
    
    if (col > 0 && is_valid_location(row, col - 1)) {
        if (find_path(row, col - 1, destination_row, destination_col)) {
            printf("(%d, %d)\n", row, col - 1);
            return true;
        }
    }
    
    if (col < COLUMNS - 1 && is_valid_location(row, col + 1)) {
        if (find_path(row, col + 1, destination_row, destination_col)) {
            printf("(%d, %d)\n", row, col + 1);
            return true;
        }
    }
    
    return false;
}

int main() {
    
    int start_row = 1, start_col = 1;
    int destination_row = 18, destination_col = 18;
    
    printf("Path from (%d, %d) to (%d, %d):\n", start_row, start_col, destination_row, destination_col);
    
    if (!find_path(start_row, start_col, destination_row, destination_col)) {
        printf("No path found!\n");
    }
    
    return 0;
}
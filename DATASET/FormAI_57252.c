//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
// Ken Thompson-style Maze Route Finder

/* This program finds a path through a maze given as 2D array filled with 0's and 1's,
where 0's represent the walls and 1's represent the empty spaces.
The program uses a recursive algorithm to explore all possible paths until it finds the exit.
*/

#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'0','0','0','0','0','0','0','0','0','0'},
    {'0','1','1','1','1','0','0','0','0','0'},
    {'0','0','0','0','1','0','0','0','0','0'},
    {'0','0','0','0','1','0','0','0','0','0'},
    {'0','0','0','0','1','1','1','1','1','0'},
    {'0','0','0','0','0','0','0','0','1','0'},
    {'0','0','0','0','0','0','0','0','1','0'},
    {'0','0','0','0','0','0','0','0','1','0'},
    {'0','0','0','0','0','0','0','0','1','0'},
    {'0','0','0','0','0','0','0','0','1','0'}
};

void print_maze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    if(maze[row][col] == '0') {
        return false;
    }
    return true;
}

bool find_path(int row, int col) {
    // Mark the current cell as visited
    maze[row][col] = '2';

    // Destination reached
    if(row == ROWS - 1 && col == COLS - 1) {
        return true;
    }

    // Try to move in all directions
    if(is_valid_move(row - 1, col) && find_path(row - 1, col)) { // Up
        return true;
    }
    if(is_valid_move(row, col + 1) && find_path(row, col + 1)) { // Right
        return true;
    }
    if(is_valid_move(row + 1, col) && find_path(row + 1, col)) { // Down
        return true;
    }
    if(is_valid_move(row, col - 1) && find_path(row, col - 1)) { // Left
        return true;
    }

    // No valid move was found, backtrack
    maze[row][col] = '1';
    return false;
}

int main() {
    printf("Original Maze:\n");
    print_maze();

    if(find_path(0, 0)) {
        printf("Path Found:\n");
        print_maze();
    } else {
        printf("No Path Found\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#define ROW 12
#define COLUMN 12

char maze[ROW][COLUMN] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

int row_start = 1;
int col_start = 1;
int row_end = 9;
int col_end = 10;

void print_maze() {
    int i, j;
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COLUMN; ++j)
            printf("%c", maze[i][j]);
        printf("\n");
    }
    printf("\n");
}

int solve_maze(int row, int col) {
    if (maze[row][col] == 'X')
        return 1;
 
    if (maze[row][col] == '#' || maze[row][col] == '.')
        return 0;
    
    maze[row][col] = '.';
    print_maze();

    if (solve_maze(row, col - 1)) {           // check left
        maze[row][col] = 'X';
        print_maze();
        return 1;
    }
    
    if (solve_maze(row - 1, col)) {           // check up
        maze[row][col] = 'X';
        print_maze();
        return 1;
    }
    
    if (solve_maze(row, col + 1)) {           // check right
        maze[row][col] = 'X';
        print_maze();
        return 1;
    }
    
    if (solve_maze(row + 1, col)) {           // check down
        maze[row][col] = 'X';
        print_maze();
        return 1;
    }
    
    return 0;
}

int main() {
    print_maze();
    solve_maze(row_start, col_start);
    print_maze();
    return 0;
}
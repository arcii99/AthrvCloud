//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>

#define ROWS 9
#define COLS 9

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1},
};

int start_row, start_col, end_row, end_col;
int solution[ROWS][COLS];

void print_maze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_solution() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(solution[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int solve(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    
    if(maze[row][col] == 1) {
        return 0;
    }
    
    if(row == end_row && col == end_col) {
        solution[row][col] = 1;
        return 1;
    }
    
    maze[row][col] = 1;
    
    if(solve(row - 1, col) || solve(row, col + 1) || solve(row + 1, col) || solve(row, col - 1)) {
        solution[row][col] = 1;
        return 1;
    }
    
    return 0;
}

int main() {
    start_row = 1;
    start_col = 7;
    end_row = 7;
    end_col = 1;
    
    print_maze();
    
    if(solve(start_row, start_col)) {
        print_solution();
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
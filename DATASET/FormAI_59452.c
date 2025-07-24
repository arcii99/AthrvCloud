//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>

#define ROW 5
#define COL 8

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
};

int visited[ROW][COL];

int startRow = 1;
int startCol = 1;
int endRow = 3;
int endCol = 6;

int solve_maze(int row, int col) {
    if(row == endRow && col == endCol) {
        return 1;
    }
    
    if(maze[row][col] == 0 && visited[row][col] == 0) {
        visited[row][col] = 1;
        
        if(solve_maze(row+1, col) == 1) { //check down
            printf("(%d, %d) ",row+1, col);
            return 1;
        }
        if(solve_maze(row, col+1) == 1) { //check right
            printf("(%d, %d) ",row, col+1);
            return 1;
        }
        if(solve_maze(row-1, col) == 1) { //check up
            printf("(%d, %d) ",row-1, col);
            return 1;
        }
        if(solve_maze(row, col-1) == 1) { //check left
            printf("(%d, %d) ",row, col-1);
            return 1;
        }
        
        visited[row][col] = 0; //backtrack
        return 0;
    }
    return 0;
}

int main() {
    printf("Starting point: (%d, %d)\n", startRow, startCol);
    if(solve_maze(startRow, startCol) == 0) {
        printf("No solution found.");
    }
    return 0;
}
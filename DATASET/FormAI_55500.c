//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5

int is_valid_move(int mov_row, int mov_col, int maze[ROW][COL], int visited[ROW][COL]) {
    return (mov_row >= 0) && (mov_row < ROW) && (mov_col >= 0) && (mov_col < COL) && maze[mov_row][mov_col] && !visited[mov_row][mov_col];
}

int dfs(int row, int col, int target_row, int target_col, int maze[ROW][COL], int visited[ROW][COL], int row_path[], int col_path[], int step) {
    if (row == target_row && col == target_col) {
        row_path[step] = row;
        col_path[step] = col;
        return 1;
    }
    
    visited[row][col] = 1;
    if (is_valid_move(row-1, col, maze, visited)) {
        row_path[step] = row;
        col_path[step] = col;
        if (dfs(row-1, col, target_row, target_col, maze, visited, row_path, col_path, step+1))
            return 1;
    }
    
    if (is_valid_move(row, col+1, maze, visited)) {
        row_path[step] = row;
        col_path[step] = col;
        if (dfs(row, col+1, target_row, target_col, maze, visited, row_path, col_path, step+1))
            return 1;
    }
    
    if (is_valid_move(row+1, col, maze, visited)) {
        row_path[step] = row;
        col_path[step] = col;
        if (dfs(row+1, col, target_row, target_col, maze, visited, row_path, col_path, step+1))
            return 1;
    }
    
    if (is_valid_move(row, col-1, maze, visited)) {
        row_path[step] = row;
        col_path[step] = col;
        if (dfs(row, col-1, target_row, target_col, maze, visited, row_path, col_path, step+1))
            return 1;
    }
    
    visited[row][col] = 0;
    return 0;
}

void print_maze(int maze[ROW][COL]) {
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_solution_path(int row_path[], int col_path[], int step) {
    for (int i=step-1; i>=0; i--) {
        printf("(%d, %d) -> ",row_path[i],col_path[i]);
    }
}

int main() {
    int maze[ROW][COL] = { {1, 1, 0, 0, 0},
                           {1, 1, 1, 1, 0},
                           {0, 0, 1, 0, 0},
                           {0, 1, 1, 1, 1},
                           {0, 0, 0, 0, 1} };
    
    printf("Maze:\n");
    print_maze(maze);
    
    int visited[ROW][COL] = { {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0} };
    
    int start_row = 0, start_col = 0;
    int target_row = 4, target_col = 4;
    int row_path[ROW*COL];
    int col_path[ROW*COL];
    int step = 0;
    
    printf("\nSearching for path from (%d, %d) to (%d, %d):\n",start_row,start_col,target_row,target_col);
    
    if (dfs(start_row, start_col, target_row, target_col, maze, visited, row_path, col_path, step)) {
        printf("Solution path:\n");
        print_solution_path(row_path, col_path, step);
    }
    else {
        printf("No solution path.\n");
    }
    
    return 0;
}
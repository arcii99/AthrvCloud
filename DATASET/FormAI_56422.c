//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define START_ROW 1
#define START_COL 1
#define END_ROW 8
#define END_COL 8

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'}
};

int visited[ROWS][COLS];
int moves[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int find_path(int row, int col)
{
    visited[row][col] = 1;
    
    if (row == END_ROW && col == END_COL) {
        return 1;
    }
    
    for (int i = 0; i < 4; i++) {
        int new_row = row + moves[i][0];
        int new_col = col + moves[i][1];
        if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS && !visited[new_row][new_col] && maze[new_row][new_col] != '#') {
            if (find_path(new_row, new_col)) {
                return 1;
            }
        }
    }
    
    visited[row][col] = 0;
    return 0;
}

int main()
{
    printf("Finding path from (%d,%d) to (%d,%d)...\n", START_ROW, START_COL, END_ROW, END_COL);
    
    if (find_path(START_ROW, START_COL)) {
        printf("Path found!\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (visited[i][j]) {
                    printf("X ");
                } else {
                    printf("%c ", maze[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("No path found.\n");
    }
    
    return 0;
}
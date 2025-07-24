//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10
#define START_ROW 0
#define START_COLUMN 0
#define END_ROW 9
#define END_COLUMN 9

char maze[ROWS][COLUMNS] = {
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '#', '#', '-', '#', '#', '#', '-', '#', '-'},
    {'-', '#', '#', '-', '#', '-', '#', '-', '#', '-'},
    {'-', '#', '#', '#', '#', '-', '#', '-', '#', '-'},
    {'-', '#', '-', '-', '-', '-', '#', '-', '#', '-'},
    {'-', '#', '#', '#', '#', '#', '#', '#', '#', '-'},
    {'-', '#', '-', '#', '#', '-', '-', '-', '-', '-'},
    {'-', '#', '#', '#', '#', '#', '#', '#', '#', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '#', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
};

bool visited[ROWS][COLUMNS] = {
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false, false, false, false}
};

int directions[][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void printMaze()
{
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int row, int column)
{
    if(row >= 0 && row < ROWS && column >= 0 && column < COLUMNS && maze[row][column] != '#' && !visited[row][column]){
        return true;
    }
    return false;
}

void findPath(int row, int column)
{
    if(row == END_ROW && column == END_COLUMN){
        visited[row][column] = true;
        printMaze();
        exit(0);
    }
    visited[row][column] = true;
    for(int i = 0; i < 4; i++){
        int next_row = row + directions[i][0];
        int next_column = column + directions[i][1];
        if(isSafe(next_row, next_column)){
            maze[next_row][next_column] = 'x';
            findPath(next_row, next_column);
            maze[next_row][next_column] = '-';
        }
    }
    visited[row][column] = false;
}

int main()
{
    printf("Maze:\n");
    printMaze();
    printf("\nFinding path...\n");
    findPath(START_ROW, START_COLUMN);
    printf("No path found!\n");
    return 0;
}
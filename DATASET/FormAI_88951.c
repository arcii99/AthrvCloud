//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

/* function to print the maze */
void printMaze(char maze[][COLS], int startRow, int startCol, int endRow, int endCol) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            if(i == startRow && j == startCol) {
                printf("| S ");
            } else if(i == endRow && j == endCol) {
                printf("| E ");
            } else {
                printf("| %c ", maze[i][j]);
            }
        }
        printf("|\n");
    }
}

/* function to find the path from start to end */
void findPath(char maze[][COLS], int startRow, int startCol, int endRow, int endCol) {
    int path[ROWS*COLS][2], top=-1;
    int visited[ROWS][COLS], flag=0;
    memset(visited, 0, sizeof(visited));
    visited[startRow][startCol] = 1;
    path[++top][0] = startRow;
    path[top][1] = startCol;
    
    while(top >= 0) {
        int row = path[top][0];
        int col = path[top][1];
        if(row == endRow && col == endCol) {
            flag = 1;
            break;
        }
        top--;
        if(row>0 && maze[row-1][col]=='0' && visited[row-1][col]==0) {
            path[++top][0] = row-1;
            path[top][1] = col;
            visited[row-1][col] = 1;
        }
        if(col>0 && maze[row][col-1]=='0' && visited[row][col-1]==0) {
            path[++top][0] = row;
            path[top][1] = col-1;
            visited[row][col-1] = 1;
        }
        if(row<ROWS-1 && maze[row+1][col]=='0' && visited[row+1][col]==0) {
            path[++top][0] = row+1;
            path[top][1] = col;
            visited[row+1][col] = 1;
        }
        if(col<COLS-1 && maze[row][col+1]=='0' && visited[row][col+1]==0) {
            path[++top][0] = row;
            path[top][1] = col+1;
            visited[row][col+1] = 1;
        }
    }
    if(flag == 0) {
        printf("\nPath not found!\n\n");
    } else {
        // print the path
        printf("\nPath:\n");
        for(int i=top;i>=0;i--) {
            printf("(%d,%d)\n", path[i][0], path[i][1]);
        }
        printf("\n");
    }
}

int main() {
    char maze[ROWS][COLS] = {
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
        {'0', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '1', '1', '0', '1', '1', '1', '1', '0', '1'},
        {'0', '1', '0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '1', '1', '0', '1', '0', '1', '1', '1', '0'},
        {'0', '1', '0', '0', '1', '0', '1', '0', '0', '0'},
        {'0', '1', '0', '1', '1', '0', '1', '0', '1', '0'},
        {'0', '1', '1', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}
    };
    int startRow = 1, startCol = 1;
    int endRow = 8, endCol = 9;
    
    printf("\nMaze:\n");
    printMaze(maze, startRow, startCol, endRow, endCol);
    
    findPath(maze, startRow, startCol, endRow, endCol);
    
    return 0;
}
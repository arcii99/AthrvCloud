//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 20     // maximum number of rows in the maze
#define COLS 20     // maximum number of columns in the maze

void printMaze(char maze[][COLS], int rows, int cols) {
    // print the maze with the start and end points indicated
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            if (maze[i][j] == 'S') {
                printf("S ");
            } else if (maze[i][j] == 'E') {
                printf("E ");
            } else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int solveMaze(char maze[][COLS], int rows, int cols, int startR, int startC,
              int endR, int endC, int visited[][COLS], int path[][2], int* pathLen) {
    // implement a depth-first search to find a path from start to end
    // returns 1 if a path was found, 0 if no path exists
    // the path and pathLen parameters are used to store the path from start to end
    // visited is used to keep track of the cells that have already been visited
    visited[startR][startC] = 1;
    path[*pathLen][0] = startR;
    path[*pathLen][1] = startC;
    ++*pathLen;
    if (startR == endR && startC == endC) {
        return 1;
    }
    // check all neighboring cells
    if (startR > 0 && maze[startR-1][startC] != '#' && !visited[startR-1][startC]) {
        if (solveMaze(maze, rows, cols, startR-1, startC, endR, endC, visited, path, pathLen)) {
            return 1;
        }
    }
    if (startR < rows-1 && maze[startR+1][startC] != '#' && !visited[startR+1][startC]) {
        if (solveMaze(maze, rows, cols, startR+1, startC, endR, endC, visited, path, pathLen)) {
            return 1;
        }
    }
    if (startC > 0 && maze[startR][startC-1] != '#' && !visited[startR][startC-1]) {
        if (solveMaze(maze, rows, cols, startR, startC-1, endR, endC, visited, path, pathLen)) {
            return 1;
        }
    }
    if (startC < cols-1 && maze[startR][startC+1] != '#' && !visited[startR][startC+1]) {
        if (solveMaze(maze, rows, cols, startR, startC+1, endR, endC, visited, path, pathLen)) {
            return 1;
        }
    }
    // if no path was found, backtrack and try a different path
    --*pathLen;
    visited[startR][startC] = 0;
    return 0;
}

int main() {
    // read in the maze from a file
    FILE* mazeFile = fopen("maze.txt", "r");
    if (mazeFile == NULL) {
        printf("Error opening maze file!\n");
        return 1;
    }
    char maze[ROWS][COLS];
    memset(maze, 0, sizeof(maze));
    memset(maze, '#', ROWS);    // set the edges of the maze to be walls
    char buffer[COLS+1];
    int row = 1;
    while (fgets(buffer, sizeof(buffer), mazeFile) != NULL) {
        buffer[strcspn(buffer, "\r\n")] = '\0';    // remove any trailing newline characters
        strncpy(maze[row]+1, buffer, COLS-2);       // copy the contents of the buffer into the maze row
        ++row;
        if (row >= ROWS-1) {
            break;
        }
    }
    fclose(mazeFile);
    int rows = row-1;
    int cols = strlen(maze[0]+1);
    memset(maze[rows], '#', cols);  // set the bottom row of the maze to be walls
    
    int startR, startC, endR, endC;
    // find the starting and ending points in the maze
    for (int i=0; i<=rows; ++i) {
        for (int j=0; j<=cols; ++j) {
            if (maze[i][j] == 'S') {
                startR = i;
                startC = j;
            } else if (maze[i][j] == 'E') {
                endR = i;
                endC = j;
            }
        }
    }
    
    // solve the maze
    int visited[ROWS][COLS] = {{0}};
    int path[ROWS*COLS][2];
    int pathLen = 0;
    if (solveMaze(maze, rows, cols, startR, startC, endR, endC, visited, path, &pathLen)) {
        // print the path
        printf("The path from start to end is:\n");
        for (int i=0; i<pathLen; ++i) {
            printf("(%d,%d)", path[i][0], path[i][1]);
            if (i < pathLen-1) {
                printf(" -> ");
            }
        }
        printf("\n");
        // update the maze with the path
        for (int i=0; i<pathLen; ++i) {
            maze[path[i][0]][path[i][1]] = '*';
        }
    } else {
        printf("No path was found!\n");
    }
    
    // output the maze with the path and starting/ending points
    printMaze(maze, rows, cols);
    
    return 0;
}
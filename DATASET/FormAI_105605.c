//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#define ROW 5       //maximum number of rows in maze
#define COL 5       //maximum number of columns in maze
#define VALID 1     //1 is considered as a valid or accessible cell
#define INVALID 0   //0 is considered as an invalid or inaccessible cell

struct Point {
   int row, col;
};

//function to print the maze
void printMaze(int maze[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

//function to check if a given cell is valid or not
int isValid(int maze[ROW][COL], int row, int col) {
    if(row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == VALID) {
        return 1;
    }
    return 0;
}

//function to recursively find the path from (0, 0) to (ROW-1, COL-1)
int findPath(int maze[ROW][COL], int row, int col, struct Point path[ROW*COL], int index) {
    if(row == ROW-1 && col == COL-1 && maze[row][col] == VALID) {
        path[index].row = row;
        path[index].col = col;
        return 1;
    }
    if(isValid(maze, row, col)) {
        path[index].row = row;
        path[index].col = col;
        maze[row][col] = INVALID;
        if(findPath(maze, row+1, col, path, index+1)) {
            return 1;
        }
        if(findPath(maze, row, col+1, path, index+1)) {
            return 1;
        }
        if(findPath(maze, row-1, col, path, index+1)) {
            return 1;
        }
        if(findPath(maze, row, col-1, path, index+1)) {
            return 1;
        }
        maze[row][col] = VALID;
    }
    return 0;
}

int main() {
    int maze[ROW][COL] = {{1,0,1,1,1},
                          {1,0,1,0,1},
                          {1,0,1,0,1},
                          {1,0,1,0,1},
                          {1,1,1,0,1}};
    struct Point path[ROW*COL];
    int pathExists = findPath(maze, 0, 0, path, 0);

    if(pathExists) {
        printf("Path exists from start to end.\n\nPath:\n");
        for(int i = 0; i < ROW*COL; i++) {
            if(path[i].row == ROW-1 && path[i].col == COL-1) {
                printf("(%d,%d)",path[i].row,path[i].col);
            }
            else {
                printf("(%d,%d)-> ",path[i].row,path[i].col);
            }
        }
        printMaze(maze);
    }
    else {
        printf("Path does not exist from start to end.");
        printMaze(maze);
    }
    return 0;
}
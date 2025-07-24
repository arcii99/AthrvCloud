//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,0,0,0,1},
    {1,1,0,1,0,0,1,1,0,1},
    {1,0,0,1,0,1,1,1,0,1},
    {1,0,1,1,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

struct Coordinate {
    int row;
    int col;
}start, end;

int findPath(int row, int col) {
    if(maze[row][col] == 0) {
        maze[row][col] = 2;
        if((row == end.row) && (col == end.col)) {
            return 1;
        }

        if((row > 0) && findPath(row-1,col)) {
            return 1;
        }
        if((row < ROW-1) && findPath(row+1,col)) {
            return 1;
        }
        if((col > 0) && findPath(row,col-1)) {
            return 1;
        }
        if((col < COL-1) && findPath(row,col+1)) {
            return 1;
        }   
        maze[row][col] = 0;
    }
    return 0;
}

int main() {
    start.row = 1;
    start.col = 1;

    end.row = 8;
    end.col = 8;

    findPath(start.row, start.col);

    // Print the maze with the path marked
    for(int row=0; row<ROW; row++) {
        for(int col=0; col<COL; col++) {
            if(maze[row][col] == 2) {
                printf("x ");
            } else {
                printf("%d ", maze[row][col]);
            }
        }
        printf("\n");
    }

    return 0;
}
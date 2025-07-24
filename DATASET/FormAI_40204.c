//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {{1,0,0,0,0,0,0,0,0,0},
                      {1,1,1,1,0,1,1,1,1,1},
                      {0,0,0,1,0,1,0,0,0,1},
                      {0,1,1,1,0,1,1,1,0,1},
                      {0,0,0,0,0,0,0,0,0,1},
                      {1,1,1,1,1,1,0,1,1,1},
                      {0,0,0,0,0,0,0,1,0,1},
                      {0,1,1,1,1,1,1,1,0,1},
                      {0,0,0,0,0,0,0,0,0,1},
                      {1,1,1,1,1,1,1,1,1,1}};

int path[ROW*COL], count=0;

void findPath(int row, int col) {
    // base case
    if (row == ROW-1 && col == COL-1) {
        // reached end of maze, print path
        for (int i = 0; i < count; i++) {
            printf("(%d,%d) ", path[i]/COL, path[i]%COL);
        }
        printf("(%d,%d) ", row, col);
        printf("\n");
    }
    
    // check if current position is a valid move
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1) {
        // add current position to path
        path[count++] = row*COL + col;
        
        // mark current position as visited
        maze[row][col] = -1;
        
        // check all possible moves from current position
        findPath(row-1, col);
        findPath(row+1, col);
        findPath(row, col-1);
        findPath(row, col+1);
        
        // remove current position from path and mark as unvisited
        path[--count] = 0;
        maze[row][col] = 1;
    }
}

int main() {
    // start from (0,0)
    findPath(0, 0);
    
    return 0;
}
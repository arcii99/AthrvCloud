//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

int maze[ROWS][COLS];

void generateMaze(int row, int col) {
    // initialize grid with walls
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            maze[i][j] = 1;
        }
    }
    
    // set starting and ending points
    maze[0][0] = 0;
    maze[row - 1][col - 1] = 0;
    
    // use recursive backtracking algorithm to carve out the maze
    srand(time(NULL));
    int r, c;
    while(1) {
        r = rand() % (row - 2) + 1;
        c = rand() % (col - 2) + 1;
        if(maze[r][c] == 1) {
            int walls = 0;
            if(maze[r - 1][c] == 0) walls++;
            if(maze[r + 1][c] == 0) walls++;
            if(maze[r][c - 1] == 0) walls++;
            if(maze[r][c + 1] == 0) walls++;
            if(walls == 1) {
                maze[r][c] = 0;
            }
        }
        int finish = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(maze[i][j] == 1) {
                    finish = 1;
                    break;
                }
            }
            if(finish == 1) break;
        }
        if(finish == 0) break;
    }
}

int main() {
    generateMaze(ROWS, COLS);
    
    // print maze
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 1) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
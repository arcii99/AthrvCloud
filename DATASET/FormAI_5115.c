//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 15
#define COL_SIZE 15

int maze[ROW_SIZE][COL_SIZE];

void initialize() {
    srand(time(NULL));
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            if(i == 0 || j == 0 || i == ROW_SIZE-1 || j == COL_SIZE-1) {
                maze[i][j] = 1; // set maze border to be walls
            } else if(i % 2 == 0 && j % 2 == 0) {
                maze[i][j] = 1; // set every other cell to be walls
            } else {
                maze[i][j] = 0; // set other cells to be empty (paths)
            }
        }
    }
}

void generateMaze(int row, int col) {
    // check out neighbors
    enum direction {north, east, south, west};
    int dirOrder[] = {north, east, south, west};
    for(int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int dir = dirOrder[randomIndex];
        int nextRow, nextCol;
        if(dir == north) {
            nextRow = row - 2;
            nextCol = col;
        } else if(dir == east) {
            nextRow = row;
            nextCol = col + 2;
        } else if(dir == south) {
            nextRow = row + 2;
            nextCol = col;
        } else if(dir == west) {
            nextRow = row;
            nextCol = col - 2;
        }
        if(nextRow >= 0 && nextRow < ROW_SIZE && nextCol >= 0 && nextCol < COL_SIZE) {
            if(maze[nextRow][nextCol] == 0) {
                // if next cell is empty, carve a path
                maze[nextRow][nextCol] = 1;
                maze[(row+nextRow)/2][(col+nextCol)/2] = 1;
                generateMaze(nextRow, nextCol);
            }
        }
    }
}

void drawMaze() {
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            if(maze[i][j] == 1) {
                printf("[]");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    initialize();
    generateMaze(1, 1);
    drawMaze();
    return 0;
}
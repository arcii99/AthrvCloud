//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL 0
#define PATH 1

int maze[ROWS][COLS];

void initializeMaze(){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            maze[i][j] = WALL;
        }
    }
}

void printMaze(){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int row, int col){
    maze[row][col] = PATH;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int i, j, direct, temp;
    for(i = 0; i < 4; i++){
        direct = rand() % 4;
        for(j = 0; j < 4; j++){
            temp = directions[direct][0];
            directions[direct][0] = directions[j][0];
            directions[j][0] = temp;
            temp = directions[direct][1];
            directions[direct][1] = directions[j][1];
            directions[j][1] = temp;
        }
        int nextRow = row + directions[direct][0] * 2;
        int nextCol = col + directions[direct][1] * 2;
        if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && maze[nextRow][nextCol] == WALL){
            maze[row + directions[direct][0]][col + directions[direct][1]] = PATH;
            generateMaze(nextRow, nextCol);
        }
    }
}

int main(){
    srand(time(NULL));
    initializeMaze();
    generateMaze(1, 1);
    printMaze();
    return 0;
}
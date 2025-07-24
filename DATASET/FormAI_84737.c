//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

int maze[MAX_ROWS][MAX_COLS];

void initializeMaze(int rows, int cols){
    // initialize all cells to 1
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            maze[i][j] = 1;
        }
    }

    // randomly select starting position
    int startRow = rand() % rows;
    int startCol = rand() % cols;

    // set starting position to 0
    maze[startRow][startCol] = 0;

    // randomly select ending position
    int endRow = rand() % rows;
    int endCol = rand() % cols;

    // set ending position to 0
    maze[endRow][endCol] = 0;
}

void printMaze(int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(0));
    int rows = rand() % MAX_ROWS + 1;
    int cols = rand() % MAX_COLS + 1;

    initializeMaze(rows, cols);
    printMaze(rows, cols);

    return 0;
}
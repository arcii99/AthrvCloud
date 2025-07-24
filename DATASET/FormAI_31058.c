//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#define ROW 8
#define COL 10

void printSolution(int arr[ROW][COL]);

void mazeSolver(int maze[ROW][COL], int row, int col, int arr[ROW][COL]){
    if(row == ROW-1 && col == COL-1){
        arr[row][col] = 1;
        printSolution(arr);
    } else {
        if(maze[row][col] == 1){
            arr[row][col] = 1;
            if(col < COL-1){
                mazeSolver(maze, row, col+1, arr);
            }
            if(row < ROW-1){
                mazeSolver(maze, row+1, col, arr);
            }
            if(col > 0){
                mazeSolver(maze, row, col-1, arr);
            }
            if(row > 0){
                mazeSolver(maze, row-1, col, arr);
            }
            arr[row][col] = 0;
        }
    }
}

void printSolution(int arr[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int maze[ROW][COL] = {
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    int arr[ROW][COL] = {{0}};
    mazeSolver(maze, 0, 0, arr);
    return 0;
}
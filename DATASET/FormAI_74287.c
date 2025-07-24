//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void printMaze(int maze[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(maze[i][j] == 0){
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void createMaze(int maze[ROWS][COLS], int row, int col){
    int directions[] = {-1, 0, 1, 0, -1};
    int shuffle[] = {0, 1, 2, 3};
    int temp;
    for(int i=0; i<4; i++){
        int r = (rand()%4)+i;
        temp = shuffle[i];
        shuffle[i] = shuffle[r];
        shuffle[r] = temp;
    }
    maze[row][col] = 1;
    for(int i=0; i<4; i++){
        int r = row + directions[shuffle[i]];
        int c = col + directions[shuffle[i]+1];
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || maze[r][c] != 0){
            continue;
        }
        if(directions[shuffle[i]] == -1){
            maze[row-1][col] = 1;
        }else if(directions[shuffle[i]] == 1){
            maze[row+1][col] = 1;
        }else if(directions[shuffle[i]+1] == -1){
            maze[row][col-1] = 1;
        }else if(directions[shuffle[i]+1] == 1){
            maze[row][col+1] = 1;
        }
        createMaze(maze, r, c);
    }
}

int main(){
    int maze[ROWS][COLS];
    srand(time(NULL));
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            maze[i][j] = 0;
        }
    }
    int startRow = rand()%ROWS;
    int startCol = rand()%COLS;
    createMaze(maze, startRow, startCol);
    printMaze(maze);
    return 0;
}
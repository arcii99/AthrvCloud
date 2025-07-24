//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];
int start_row, start_col;

void print_maze(){
    int i,j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            // print walls
            if(maze[i][j] == 1)
                printf("#");
            // print start point
            else if(i==start_row && j==start_col)
                printf("S");
            // print end point
            else if(i==ROWS-1 && j==COLS-1)
                printf("E");
            // print path
            else if(maze[i][j] == 0)
                printf(" ");
            // print unreachable points
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

void generate_maze(){
    int i,j;

    // set all points to walls
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            maze[i][j] = 1;
        }
    }

    // set starting point
    maze[start_row][start_col] = 0;

    // set random exit point
    int exit_row = rand() % ROWS;
    int exit_col = rand() % COLS;

    // set exit point
    maze[exit_row][exit_col] = 0;

    // generate maze
    int cur_row = start_row;
    int cur_col = start_col;

    while(cur_row != exit_row || cur_col != exit_col){
        int direction = rand() % 4;
        // move up
        if(direction == 0 && cur_row-1>=0 && maze[cur_row-1][cur_col] == 1){
            maze[cur_row-1][cur_col] = 0;
            cur_row--;
        }
        // move down
        else if(direction == 1 && cur_row+1<ROWS && maze[cur_row+1][cur_col] == 1){
            maze[cur_row+1][cur_col] = 0;
            cur_row++;
        }
        // move left
        else if(direction == 2 && cur_col-1>=0 && maze[cur_row][cur_col-1] == 1){
            maze[cur_row][cur_col-1] = 0;
            cur_col--;
        }
        // move right
        else if(direction == 3 && cur_col+1<COLS && maze[cur_row][cur_col+1] == 1){
            maze[cur_row][cur_col+1] = 0;
            cur_col++;
        }
    }
}

int main(void) {
    srand(time(NULL));

    // set starting point
    start_row = rand() % ROWS;
    start_col = rand() % COLS;

    printf("Generating maze...\n\n");
    generate_maze();
    printf("Maze generated!\n\n");
    print_maze();

    return 0;
}
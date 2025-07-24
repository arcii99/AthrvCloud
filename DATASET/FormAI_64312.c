//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define WALL 1
#define PATH 0

void generate_maze(int maze[ROWS][COLS]) {
    srand(time(NULL));
    
    // initialize maze with all walls
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    
    // carve out paths using randomized depth first search
    int stack[ROWS*COLS][2];
    int top = 0;
    stack[top][0] = 1;
    stack[top][1] = 1;
    int visited = 0;
    while(top != -1) {
        int cur_row = stack[top][0];
        int cur_col = stack[top][1];
        maze[cur_row][cur_col] = PATH;
        visited++;
        top--;
        int neighbors[4][2] = {{cur_row-2, cur_col}, {cur_row, cur_col-2}, {cur_row+2, cur_col}, {cur_row, cur_col+2}};
        for(int i=0; i<4; i++) {
            int next_row = neighbors[i][0];
            int next_col = neighbors[i][1];
            if(next_row <= 0 || next_row >= ROWS || next_col <= 0 || next_col >= COLS) {
                continue;
            }
            if(maze[next_row][next_col] == WALL) {
                int wall_row = cur_row + (next_row - cur_row)/2;
                int wall_col = cur_col + (next_col - cur_col)/2;
                maze[wall_row][wall_col] = PATH;
                top++;
                stack[top][0] = next_row;
                stack[top][1] = next_col;
            }
        }
    }
}

void print_maze(int maze[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == WALL) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS];
    generate_maze(maze);
    print_maze(maze);
    
    return 0;
}
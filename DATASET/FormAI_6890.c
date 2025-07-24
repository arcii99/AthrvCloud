//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10
#define WALL 1
#define PATH 0

int maze[ROW][COL] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
};

typedef struct{
    int row;
    int col;
}coordinate_t;

bool is_valid(int r, int c){
    return r >= 0 && r < ROW && c >=0 && c < COL && maze[r][c] == PATH;
}

void print_path(coordinate_t *path, int size){
    for(int i = size-1; i >= 0; i--){
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

bool solve_maze(int r, int c, coordinate_t *path, int size){
    if(r == ROW-1 && c == COL-1){
        path[size].row = r;
        path[size].col = c;
        print_path(path, size+1);
        return true;
    }

    if(is_valid(r, c)){
        maze[r][c] = WALL;
        path[size].row = r;
        path[size].col = c;

        if(solve_maze(r+1, c, path, size+1) || 
           solve_maze(r, c+1, path, size+1) || 
           solve_maze(r-1, c, path, size+1) || 
           solve_maze(r, c-1, path, size+1)){
               return true;
           }
        maze[r][c] = PATH;
    }
    return false; 
}

int main(){
    coordinate_t path[ROW * COL];
    int size = 0;

    if(solve_maze(0, 0, path, size)){
        printf("Path found!\n");
    }else{
        printf("Path not found...\n");
    }

    return 0;   
}
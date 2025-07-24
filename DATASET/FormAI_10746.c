//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 6

char maze[ROWS][COLS] = {  {'#', '#', '#', '#', '#', '#'},
                           {'#', '.', '#', '.', '.', '#'},
                           {'#', '.', '#', '.', '#', '#'},
                           {'#', '.', '.', '.', '.', '#'},
                           {'#', '#', '#', '.', '.', '#'},
                           {'#', '#', '#', '#', '#', '#'} };
int visited[ROWS][COLS] = {0};

void printMaze(char maze[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int r, int c){
    if(r < 0 || r > ROWS-1 || c < 0 || c > COLS-1 || visited[r][c] == 1 || maze[r][c] == '#')
        return 0;

    visited[r][c] = 1;
    if(maze[r][c] == '.' && r == ROWS-2 && c == COLS-2){
        maze[r][c] = '@';
        return 1;
    }else if(maze[r][c] == '.'){
        maze[r][c] = '@';
        if(solveMaze(r, c+1) || solveMaze(r+1, c) || solveMaze(r, c-1) || solveMaze(r-1, c)){
            return 1;
        }else{
            maze[r][c] = '.';
            return 0;
        }   
    }
    return 0;
}

int main(){
    printf("This program finds the shortest path through the maze.\n");
    printf("The maze legend is:\n");
    printf("    # = Wall\n");
    printf("    . = Path\n");
    printf("    @ = Path the algorithm found\n\n");
    printf("Maze before:\n");
    printMaze(maze);

    solveMaze(1, 1);

    printf("\nMaze after:\n");
    printMaze(maze);

    return 0;
}
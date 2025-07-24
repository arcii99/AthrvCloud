//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_ROWS 10       // Maze Height
#define MAZE_COLS 10       // Maze Width

#define WALL 1             // Maze Wall
#define PATH 0             // Maze Path

int maze[MAZE_ROWS][MAZE_COLS];   // Maze array

void generateMaze();    // function to generate maze
void printMaze();       // function to print maze

int main(){
    srand(time(NULL));  // generate seed for random function
    generateMaze();     // generate maze
    printMaze();        // print the maze
    return 0;
}

void generateMaze(){
    int i, j;

    // setting the borders of maze to wall
    for(i = 0; i < MAZE_ROWS; i++){
        maze[i][0] = WALL;
        maze[i][MAZE_COLS - 1] = WALL;
    }

    for(i = 0; i < MAZE_COLS; i++){
        maze[0][i] = WALL;
        maze[MAZE_ROWS - 1][i] = WALL;
    }

    // setting random walls in the maze
    for(i = 2; i < MAZE_ROWS - 2; i++){
        for(j = 2; j < MAZE_COLS - 2; j++){
            if(rand() % 2 == 0){
                maze[i][j] = WALL;
            }
            else{
                maze[i][j] = PATH;
            }
        }
    }

    // setting center of maze to path
    maze[MAZE_ROWS/2][MAZE_COLS/2] = PATH;
}

void printMaze(){
    int i, j;

    // printing the maze
    for(i = 0; i < MAZE_ROWS; i++){
        for(j = 0; j < MAZE_COLS; j++){
            if(maze[i][j] == WALL){
                printf("X ");   // printing wall
            }
            else{
                printf("  ");  // printing path
            }
        }
        printf("\n");
    }
}
//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 10
#define COL 10

// Function to generate random maze
void createMaze(int maze[ROW][COL]){
    // Generate random maze
    srand(time(NULL));
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            maze[i][j] = rand()%2;
        }
    }
    // Set start and end point
    maze[0][0] = maze[ROW-1][COL-1] = 0;
}

// Function to display the maze
void displayMaze(int maze[][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to solve the maze
void solveMaze(int maze[][COL], int x, int y){
    // Mark the current cell as visited
    maze[x][y] = 2;

    // If reached the end point
    if(x==ROW-1 && y==COL-1){
        printf("Maze is Solved\n");
        return;
    }
    // Move down
    if(x+1<ROW && maze[x+1][y]==0){
        solveMaze(maze, x+1, y);
    }
    // Move right
    if(y+1<COL && maze[x][y+1]==0){
        solveMaze(maze, x, y+1);
    }
    // Move up
    if(x-1>=0 && maze[x-1][y]==0){
        solveMaze(maze, x-1, y);
    }
    // Move left
    if(y-1>=0 && maze[x][y-1]==0){
        solveMaze(maze, x, y-1);
    }
}

int main(){
    int maze[ROW][COL];
    createMaze(maze);
    printf("Generated Maze:\n");
    displayMaze(maze);
    printf("\nSolving Maze:\n");
    solveMaze(maze, 0, 0);
    printf("\nMaze with Path:\n");
    displayMaze(maze);

    return 0;
}
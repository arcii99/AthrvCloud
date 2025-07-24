//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 15

// Function to print maze
void printMaze(int maze[][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(maze[i][j] == 0)
                printf("⬛️"); // Wall
            else if(maze[i][j] == 1)
                printf("⬜️"); // Pathway
            else
                printf("🚪"); // Exit
        }
        printf("\n");
    }
}

// Function to generate Maze using Depth First Search Algorithm
void generateMazeUsingDFS(int maze[][COLS], int row, int col){
    int rowDir[] = {0, 0, 1, -1}; // Up, down direction
    int colDir[] = {1, -1, 0, 0}; // Right, left direction
    
    maze[row][col] = 1; // Mark current cell as visited
    
    // Randomizing the direction
    int* sequence = (int*)malloc(4*sizeof(int));
    for(int i=0; i<4; i++)
        sequence[i] = i;
    for(int i=0; i<4; i++){
        int num = rand() % 4;
        int temp = sequence[i];
        sequence[i] = sequence[num];
        sequence[num] = temp;
    }
    
    // Depth First Search of Maze using Randomization of Directions
    for(int i=0; i<4; i++){
        int newRow = row + rowDir[sequence[i]];
        int newCol = col + colDir[sequence[i]];
        if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS){
            if(maze[newRow][newCol] == 0){
                if(sequence[i] == 0)
                    maze[row][col+1] = 1;
                if(sequence[i] == 1)
                    maze[row][col-1] = 1;
                if(sequence[i] == 2)
                    maze[row+1][col] = 1;
                if(sequence[i] == 3)
                    maze[row-1][col] = 1;
                generateMazeUsingDFS(maze, newRow, newCol);
            }
        }
    }
    free(sequence);
}

int main(){
    int maze[ROWS][COLS];
    srand(time(NULL));
    
    // Initializing Maze with Walls
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(i == 0 || i == ROWS-1 || j == 0 || j == COLS-1)
                maze[i][j] = 0; // Wall
            else
                maze[i][j] = -1; // Unvisited Cell
        }
    }
    
    // Generating Maze
    generateMazeUsingDFS(maze, 1, 1);
    
    // Setting Exit of Maze
    maze[ROWS-2][COLS-2] = 2;

    // Printing Maze
    printMaze(maze);
    return 0;
}
//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constants for maze size
#define ROWS 20
#define COLS 20

//Constants for cell values
#define WALL 0
#define PATH 1

//Function declarations
void generateMaze(int maze[][COLS]);
void displayMaze(int maze[][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL)); //Seed for random number generator
    
    generateMaze(maze);
    displayMaze(maze);
    
    return 0;
}

//Function to generate maze
void generateMaze(int maze[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                maze[i][j] = WALL; //Create outer walls of the maze
            } else {
                maze[i][j] = rand()%2; //Randomly create walls and paths
            }
        }
    }
}

//Function to display maze
void displayMaze(int maze[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(maze[i][j] == WALL) {
                printf("██"); //Display walls as block characters
            } else {
                printf("  "); //Display paths as spaces
            }
        }
        printf("\n");
    }
}
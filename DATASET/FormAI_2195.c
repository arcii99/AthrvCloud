//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Maze size
#define WALL 0
#define PATH 1

// Function to print the maze
void printMaze(int maze[][SIZE]){
    printf(" ");
    for(int i=0; i<SIZE; i++){
        printf("___");
    }
    printf("\n");

    for(int i=0; i<SIZE; i++){
        printf("|");
        for(int j=0; j<SIZE; j++){
            if(maze[i][j]==WALL){
                printf("###");
            }
            else{
                printf("   ");
            }
            printf("|");
        }
        printf("\n ");
        for(int j=0; j<SIZE; j++){
            printf("___");
        }
        printf("\n");
    }
}

int main(){
    srand(time(0)); // Setting random seed

    int maze[SIZE][SIZE]; // Maze array

    // Initializing maze with walls
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            maze[i][j] = WALL;
        }
    }

    // Starting position
    int x = 1;
    int y = 1;

    // Marking starting position as path
    maze[x][y] = PATH;

    // Possible moves
    int moves[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    // Loop until maze is complete
    while(x != SIZE-2 || y != SIZE-2){
        int r = rand() % 4; // Randomly choose a move

        // Check for boundary and if move is valid
        if(x + moves[r][0] < SIZE-1 && x + moves[r][0] > 0 && y + moves[r][1] < SIZE-1 && y + moves[r][1] > 0 && maze[x + moves[r][0]][y + moves[r][1]] == WALL){

            // Mark as path
            x += moves[r][0];
            y += moves[r][1];
            maze[x][y] = PATH;

            // Check if we hit a dead end
            int deadend = 1;
            for(int i=0; i<4; i++){
                if(maze[x + moves[i][0]][y + moves[i][1]] == WALL){
                    deadend = 0;
                    break;
                }
            }

            // If its a deadend, backtrack
            if(deadend){
                while(deadend){
                    r = rand() % 4; // Choose a random previous move
                    if(maze[x + moves[r][0]][y + moves[r][1]] == PATH){
                        x += moves[r][0];
                        y += moves[r][1];
                        deadend = 0;
                    }
                }
            }
        }
    }

    // Print the maze
    printMaze(maze);

    return 0;
}
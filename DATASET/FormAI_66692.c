//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

int maze[ROWS][COLS];
int visited[ROWS][COLS];

//Function Prototypes
void generateMaze();
void printMaze();

int main() {
    //Random Number Generation
    srand(time(NULL));
    //Building Maze
    generateMaze();
    //Printing Maze
    printMaze();

    return 0;
}

//Generates Maze
void generateMaze() {
    int x = 0, y = 0;
    int i, j;

    //Initializing the Maze and visited arrays
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = rand()%2;
            }
            visited[i][j] = 0;
        }
    }

    //Selecting a starting point
    x = rand()%ROWS;
    y = rand()%COLS;

    //Marking starting point non-visited
    visited[x][y] = 1;

    //Recursive Call
    generateMazeRec(x, y);
}

//Recursive Function to Generate Maze
void generateMazeRec(int x, int y) {
    int i, j;
    int rand_dir = rand()%4;
    int new_x, new_y;

    //Random Direction in which to Move
    for(i=0; i<4; i++) {
        rand_dir = rand()%4;

        //Calculating new x and y
        switch(rand_dir) {
            case 0:
                new_x = x-1;
                new_y = y;
                break;
            case 1:
                new_x = x;
                new_y = y+1;
                break;
            case 2:
                new_x = x+1;
                new_y = y;
                break;
            case 3:
                new_x = x;
                new_y = y-1;
                break;
        }

        //Making sure new_x and new_y are within bounds
        if(new_x<0 || new_y<0 || new_x>=ROWS || new_y>=COLS) {
            continue;
        }

        //Making sure new location is not already visited
        if(visited[new_x][new_y]) {
            continue;
        }

        //Breaking current wall
        if(x == new_x) {
            if(y < new_y) {
                maze[x][y+1] = 0;
            }
            else {
                maze[x][y-1] = 0;
            }
        }
        else {
            if(x < new_x) {
                maze[x+1][y] = 0;
            }
            else {
                maze[x-1][y] = 0;
            }
        }

        //Marking new position as visited
        visited[new_x][new_y] = 1;

        //Recursive Call
        generateMazeRec(new_x, new_y);
    }
}

//Prints Maze
void printMaze() {
    int i, j;

    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(maze[i][j] == 1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
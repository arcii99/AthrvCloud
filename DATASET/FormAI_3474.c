//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 9
#define COLS 9

int maze[ROWS][COLS];

void generateMaze() {

    srand(time(NULL));

    //Set the initial state of the maze to all walls
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = -1;
        }
    }

    //Generate random pathways using depth-first search algorithm
    int x = rand() % ROWS;
    int y = rand() % COLS;
    maze[x][y] = 0; //Start position
    int stackX[ROWS*COLS], stackY[ROWS*COLS];
    int top = 0;
    stackX[top] = x;
    stackY[top] = y;

    while(top >= 0) {
        int currentX = stackX[top];
        int currentY = stackY[top];
        top--;

        //Check if the current position has unvisited neighbors
        int unvisitedNeighbors[4] = {-1, -1, -1, -1};
        int numUnvisited = 0;
        if(currentX > 0 && maze[currentX-1][currentY] == -1) {
            unvisitedNeighbors[numUnvisited++] = 0; //0 = North
        }
        if(currentY < COLS - 1 && maze[currentX][currentY+1] == -1) {
            unvisitedNeighbors[numUnvisited++] = 1; //1 = East
        }
        if(currentX < ROWS - 1 && maze[currentX+1][currentY] == -1) {
            unvisitedNeighbors[numUnvisited++] = 2; //2 = South
        }
        if(currentY > 0 && maze[currentX][currentY-1] == -1) {
            unvisitedNeighbors[numUnvisited++] = 3; //3 = West
        }

        //If there are unvisited neighbors, randomly choose one and create a path
        if(numUnvisited > 0) {
            int direction = unvisitedNeighbors[rand() % numUnvisited];
            int nextX = currentX + (direction == 2 ? 1 : (direction == 0 ? -1 : 0));
            int nextY = currentY + (direction == 1 ? 1 : (direction == 3 ? -1 : 0));
            maze[nextX][nextY] = maze[currentX][currentY] + 1;
            top++;
            stackX[top] = nextX;
            stackY[top] = nextY;
        }
    }

    //Add some walls randomly to make it more interesting
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] > 0 && rand() % 10 == 0) {
                maze[i][j] = -1;
            }
        }
    }
}

void printMaze() {

    //Print the maze
    printf("Maze:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 0) {
                printf(" S ");
            }
            else if(maze[i][j] == -1) {
                printf(" X ");
            }
            else {
                printf("%2d ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {

    generateMaze();
    printMaze();

    return 0;
}
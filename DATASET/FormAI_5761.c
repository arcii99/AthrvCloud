//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

//Struct to represent a cell in the maze
typedef struct {
    int north;
    int east;
    int south;
    int west;
    int visited;
} Cell;

void generateMaze(Cell maze[][MAZE_SIZE]);
void printMaze(Cell maze[][MAZE_SIZE]);

int main(void) {
    //Seed random number generator
    srand(time(NULL));

    //Create maze array
    Cell maze[MAZE_SIZE][MAZE_SIZE];

    //Generate and print maze
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(Cell maze[][MAZE_SIZE]) {
    //Initialize cells
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j].north = 1;
            maze[i][j].east = 1;
            maze[i][j].south = 1;
            maze[i][j].west = 1;
            maze[i][j].visited = 0;
        }
    }

    //Select starting cell and mark as visited
    int currentRow = rand() % MAZE_SIZE;
    int currentCol = rand() % MAZE_SIZE;
    maze[currentRow][currentCol].visited = 1;

    //Initialize stack for backtracking
    int stackRow[MAZE_SIZE * MAZE_SIZE];
    int stackCol[MAZE_SIZE * MAZE_SIZE];
    int stackTop = 0;

    //Iterate until all cells are visited
    while (1) {
        //Mark all unvisited neighbors
        int unvisitedNeighbors = 0;
        if (currentRow > 0 && !maze[currentRow - 1][currentCol].visited) {
            ++unvisitedNeighbors;
        }
        if (currentCol < MAZE_SIZE - 1 && !maze[currentRow][currentCol + 1].visited) {
            ++unvisitedNeighbors;
        }
        if (currentRow < MAZE_SIZE - 1 && !maze[currentRow + 1][currentCol].visited) {
            ++unvisitedNeighbors;
        }
        if (currentCol > 0 && !maze[currentRow][currentCol - 1].visited) {
            ++unvisitedNeighbors;
        }

        //If there are unvisited neighbors, randomly choose one
        if (unvisitedNeighbors > 0) {
            int randomDirection = rand() % unvisitedNeighbors;
            if (currentRow > 0 && !maze[currentRow - 1][currentCol].visited) {
                if (randomDirection == 0) {
                    //Remove wall to north
                    maze[currentRow][currentCol].north = 0;
                    maze[currentRow - 1][currentCol].south = 0;

                    //Push current cell onto stack and move to new cell
                    stackRow[stackTop] = currentRow;
                    stackCol[stackTop] = currentCol;
                    ++stackTop;
                    currentRow = currentRow - 1;
                    maze[currentRow][currentCol].visited = 1;

                    continue;
                } else {
                    --randomDirection;
                }
            }
            if (currentCol < MAZE_SIZE - 1 && !maze[currentRow][currentCol + 1].visited) {
                if (randomDirection == 0) {
                    //Remove wall to east
                    maze[currentRow][currentCol].east = 0;
                    maze[currentRow][currentCol + 1].west = 0;

                    //Push current cell onto stack and move to new cell
                    stackRow[stackTop] = currentRow;
                    stackCol[stackTop] = currentCol;
                    ++stackTop;
                    currentCol = currentCol + 1;
                    maze[currentRow][currentCol].visited = 1;

                    continue;
                } else {
                    --randomDirection;
                }
            }
            if (currentRow < MAZE_SIZE - 1 && !maze[currentRow + 1][currentCol].visited) {
                if (randomDirection == 0) {
                    //Remove wall to south
                    maze[currentRow][currentCol].south = 0;
                    maze[currentRow + 1][currentCol].north = 0;

                    //Push current cell onto stack and move to new cell
                    stackRow[stackTop] = currentRow;
                    stackCol[stackTop] = currentCol;
                    ++stackTop;
                    currentRow = currentRow + 1;
                    maze[currentRow][currentCol].visited = 1;

                    continue;
                } else {
                    --randomDirection;
                }
            }
            if (currentCol > 0 && !maze[currentRow][currentCol - 1].visited) {
                if (randomDirection == 0) {
                    //Remove wall to west
                    maze[currentRow][currentCol].west = 0;
                    maze[currentRow][currentCol - 1].east = 0;

                    //Push current cell onto stack and move to new cell
                    stackRow[stackTop] = currentRow;
                    stackCol[stackTop] = currentCol;
                    ++stackTop;
                    currentCol = currentCol - 1;
                    maze[currentRow][currentCol].visited = 1;

                    continue;
                } else {
                    --randomDirection;
                }
            }
        } else {
            //If no unvisited neighbors, backtrack using stack
            if (stackTop > 0) {
                --stackTop;
                currentRow = stackRow[stackTop];
                currentCol = stackCol[stackTop];
            } else {
                break;
            }
        }
    }
}

void printMaze(Cell maze[][MAZE_SIZE]) {
    //Print top wall
    printf("+");
    for (int j = 0; j < MAZE_SIZE; j++) {
        printf("--+");
    }
    printf("\n");

    //Print each row
    for (int i = 0; i < MAZE_SIZE; i++) {
        //Print west wall
        printf("|");
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("  ");
            if (maze[i][j].west == 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");

        //Print south wall
        printf("+");
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j].south == 1) {
                printf("--");
            } else {
                printf("  ");
            }
            printf("+");
        }
        printf("\n");
    }
}
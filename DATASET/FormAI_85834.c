//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21 // must be odd
#define COLS 21 // must be odd

void generateMaze(int maze[][COLS], int rows, int cols);
void printMaze(int maze[][COLS], int rows, int cols);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));

    // initialize maze with all walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // generate maze
    generateMaze(maze, ROWS, COLS);

    // print maze
    printMaze(maze, ROWS, COLS);

    return 0;
}

void generateMaze(int maze[][COLS], int rows, int cols) {
    int visited[ROWS][COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }

    // randomly select start and add to stack
    int currentRow = 1;
    int currentCol = 1;
    maze[currentRow][currentCol] = 0;
    visited[currentRow][currentCol] = 1;

    // while there are still unvisited cells, continue generating maze
    while (1) {
        // find unvisited neighbors of current cell
        int neighbors[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}}; // left, up, right, down
        int numUnvisitedNeighbors = 0;
        int unvisitedNeighbors[4][2];

        for (int i = 0; i < 4; i++) {
            int neighborRow = currentRow + neighbors[i][0];
            int neighborCol = currentCol + neighbors[i][1];

            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                if (visited[neighborRow][neighborCol] == 0) {
                    unvisitedNeighbors[numUnvisitedNeighbors][0] = neighborRow;
                    unvisitedNeighbors[numUnvisitedNeighbors][1] = neighborCol;
                    numUnvisitedNeighbors++;
                }
            }
        }

        // if there are unvisited neighbors, randomly select one and remove wall
        if (numUnvisitedNeighbors > 0) {
            // choose random unvisited neighbor
            int randomIndex = rand() % numUnvisitedNeighbors;
            int nextRow = unvisitedNeighbors[randomIndex][0];
            int nextCol = unvisitedNeighbors[randomIndex][1];

            // remove wall between current and selected neighbor
            int wallRow = (currentRow + nextRow) / 2;
            int wallCol = (currentCol + nextCol) / 2;
            maze[wallRow][wallCol] = 0;

            // move to selected neighbor and add to stack
            currentRow = nextRow;
            currentCol = nextCol;
            maze[currentRow][currentCol] = 0;
            visited[currentRow][currentCol] = 1;
        } else {
            // backtrack to previous cell on stack
            int backtrack = 0;
            for (int i = 0; i < rows && !backtrack; i++) {
                for (int j = 0; j < cols && !backtrack; j++) {
                    if (visited[i][j] == 1 && maze[i][j] == 0) { // find previous cell with visited neighbors
                        int numVisitedNeighbors = 0;
                        int visitedNeighbors[4][2];

                        for (int k = 0; k < 4; k++) {
                            int neighborRow = i + neighbors[k][0];
                            int neighborCol = j + neighbors[k][1];

                            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                                if (visited[neighborRow][neighborCol] == 1) {
                                    visitedNeighbors[numVisitedNeighbors][0] = neighborRow;
                                    visitedNeighbors[numVisitedNeighbors][1] = neighborCol;
                                    numVisitedNeighbors++;
                                }
                            }
                        }

                        // choose random visited neighbor and remove wall
                        int randomIndex = rand() % numVisitedNeighbors;
                        int nextRow = visitedNeighbors[randomIndex][0];
                        int nextCol = visitedNeighbors[randomIndex][1];
                        int wallRow = (i + nextRow) / 2;
                        int wallCol = (j + nextCol) / 2;
                        maze[wallRow][wallCol] = 0;

                        // move back to previous cell
                        currentRow = i;
                        currentCol = j;
                        backtrack = 1;
                    }
                }
            }

            // if there are no more cells to backtrack to, exit loop
            if (!backtrack) break;
        }
    }
}

void printMaze(int maze[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 1) {
                printf("[]");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
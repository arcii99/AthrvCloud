//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 21
#define MAZE_HEIGHT 15

void generateMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);
void printMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);

int main() {
    char maze[MAZE_HEIGHT][MAZE_WIDTH];

    // Seed the random number generator
    srand(time(NULL));

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    // Initialize the maze with walls
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (i % 2 == 0 || j % 2 == 0)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
        }
    }

    // Randomized Prim's algorithm
    int startRow = rand() % (MAZE_HEIGHT / 2) * 2 + 1;
    int startCol = rand() % (MAZE_WIDTH / 2) * 2 + 1;
    maze[startRow][startCol] = ' ';
    int visited[MAZE_HEIGHT][MAZE_WIDTH] = {0};
    visited[startRow][startCol] = 1;
    int frontierRow[MAZE_WIDTH * MAZE_HEIGHT / 4] = {0};
    int frontierCol[MAZE_WIDTH * MAZE_HEIGHT / 4] = {0};
    int frontierCount = 1;
    frontierRow[0] = startRow;
    frontierCol[0] = startCol;

    while (frontierCount > 0) {
        // Choose a random frontier cell
        int frontierIndex = rand() % frontierCount;
        int row = frontierRow[frontierIndex];
        int col = frontierCol[frontierIndex];

        // Remove the frontier cell from the frontier set
        frontierRow[frontierIndex] = frontierRow[frontierCount - 1];
        frontierCol[frontierIndex] = frontierCol[frontierCount - 1];
        frontierCount--;

        // Carve a passage to a random visited neighbor
        int neighbors[4][2] = {{row-2,col},{row+2,col},{row,col-2},{row,col+2}};
        for (int i = 0; i < 4; i++) {
            int neighborRow = neighbors[i][0];
            int neighborCol = neighbors[i][1];
            if (neighborRow >= 0 && neighborRow < MAZE_HEIGHT && neighborCol >= 0 && neighborCol < MAZE_WIDTH) {
                if (visited[neighborRow][neighborCol]) {
                    if (neighborRow == row-2) maze[row-1][col] = ' ';
                    if (neighborRow == row+2) maze[row+1][col] = ' ';
                    if (neighborCol == col-2) maze[row][col-1] = ' ';
                    if (neighborCol == col+2) maze[row][col+1] = ' ';
                    break;
                }
            }
        }

        // Add any unvisited neighbors to the frontier set
        int unvisitedNeighbors[4][2] = {{row-1,col},{row+1,col},{row,col-1},{row,col+1}};
        for (int i = 0; i < 4; i++) {
            int neighborRow = unvisitedNeighbors[i][0];
            int neighborCol = unvisitedNeighbors[i][1];
            if (neighborRow >= 0 && neighborRow < MAZE_HEIGHT && neighborCol >= 0 && neighborCol < MAZE_WIDTH) {
                if (!visited[neighborRow][neighborCol]) {
                    visited[neighborRow][neighborCol] = 1;
                    frontierRow[frontierCount] = neighborRow;
                    frontierCol[frontierCount] = neighborCol;
                    frontierCount++;
                }
            }
        }
    }
}

void printMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}
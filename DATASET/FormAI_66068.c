//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

void generateMaze(int maze[][MAZE_SIZE], int row, int col) {
    srand(time(NULL)); // seed the random number generator
    int visited[MAZE_SIZE][MAZE_SIZE] = {0}; // initialize all cells as unvisited
    int direction[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}; // define the valid directions to move in the maze
    int currentRow = row, currentCol = col;
    visited[currentRow][currentCol] = 1; // mark the starting cell as visited
    while (1) {
        int numValidMoves = 0;
        int validMoves[4][2] = {0};
        for (int i=0; i<4; i++) {
            int newRow = currentRow + direction[i][0];
            int newCol = currentCol + direction[i][1];
            if (newRow>=0 && newRow<MAZE_SIZE && newCol>=0 && newCol<MAZE_SIZE && !visited[newRow][newCol]) {
                validMoves[numValidMoves][0] = newRow;
                validMoves[numValidMoves][1] = newCol;
                numValidMoves++;
            }
        }
        if (numValidMoves == 0) { // no valid moves left
            break;
        } else {
            int choice = rand() % numValidMoves; // choose a random valid move
            int newRow = validMoves[choice][0];
            int newCol = validMoves[choice][1];
            if (newRow == currentRow - 1) {
                maze[currentRow][currentCol] |= 1 << 0; // set the North connection
                maze[newRow][newCol] |= 1 << 2; // set the South connection
            } else if (newCol == currentCol - 1) {
                maze[currentRow][currentCol] |= 1 << 1; // set the West connection
                maze[newRow][newCol] |= 1 << 3; // set the East connection
            } else if (newRow == currentRow + 1) {
                maze[currentRow][currentCol] |= 1 << 2; // set the South connection
                maze[newRow][newCol] |= 1 << 0; // set the North connection
            } else {
                maze[currentRow][currentCol] |= 1 << 3; // set the East connection
                maze[newRow][newCol] |= 1 << 1; // set the West connection
            }
            currentRow = newRow;
            currentCol = newCol;
            visited[currentRow][currentCol] = 1; // mark the new cell as visited
        }
    }
}

int main() {
    int maze[MAZE_SIZE][MAZE_SIZE] = {0}; // initialize all cells as unconnected
    generateMaze(maze, 0, 0); // generate the maze starting from the top-left corner
    // print the maze
    for (int row=0; row<MAZE_SIZE; row++) {
        for (int col=0; col<MAZE_SIZE; col++) {
            printf("+");
            if (maze[row][col] & (1 << 0)) { // check North connection
                printf(" ");
            } else {
                printf("-");
            }
        }
        printf("+\n");
        for (int col=0; col<MAZE_SIZE; col++) {
            if (maze[row][col] & (1 << 1)) { // check West connection
                printf(" ");
            } else {
                printf("|");
            }
            printf(" ");
        }
        if (maze[row][MAZE_SIZE-1] & (1 << 3)) { // check East connection
            printf(" ");
        } else {
            printf("|");
        }
        printf("\n");
    }
    for (int col=0; col<MAZE_SIZE; col++) {
        printf("+");
        if (maze[MAZE_SIZE-1][col] & (1 << 2)) { // check South connection
            printf(" ");
        } else {
            printf("-");
        }
    }
    printf("+\n");
    return 0;
}
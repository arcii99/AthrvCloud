//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void generateMaze(int maze[ROWS][COLS]) {
    srand(time(NULL)); // seed random number generator with current time

    // initialize maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // randomly select starting position
    int x = rand() % ROWS;
    int y = rand() % COLS;

    // carve out maze starting from randomly selected position
    maze[x][y] = 0; // mark starting position as part of the maze
    int visited = 1; // count number of visited cells
    int total = ROWS * COLS; // total number of cells in the maze

    while (visited < total) {
        // get adjacent cells
        int adj[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int numAdj = 4;
        if (x == 0) {
            adj[0][0] = 0;
            adj[0][1] = 0;
            numAdj--;
        }
        if (y == 0) {
            adj[1][0] = 0;
            adj[1][1] = 0;
            numAdj--;
        }
        if (x == ROWS - 1) {
            adj[2][0] = 0;
            adj[2][1] = 0;
            numAdj--;
        }
        if (y == COLS - 1) {
            adj[3][0] = 0;
            adj[3][1] = 0;
            numAdj--;
        }

        // randomly select an adjacent cell to visit
        int idx = rand() % numAdj;
        int newX = x + adj[idx][0];
        int newY = y + adj[idx][1];

        // check if adjacent cell is within bounds and unvisited
        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && maze[newX][newY] == 1) {
            // remove wall between current cell and adjacent cell
            if (adj[idx][0] == -1) {
                maze[x-1][y] = 0;
            } else if (adj[idx][0] == 1) {
                maze[x+1][y] = 0;
            } else if (adj[idx][1] == -1) {
                maze[x][y-1] = 0;
            } else {
                maze[x][y+1] = 0;
            }

            // mark adjacent cell as part of the maze and update current position
            maze[newX][newY] = 0;
            x = newX;
            y = newY;
            visited++;
        }
    }
}

int main() {
    int maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}
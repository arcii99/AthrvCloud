//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

// Declare function to generate maze
void generateMaze(int maze[ROW][COL], int startRow, int startCol);

int main() {
    int maze[ROW][COL];

    // Initialize maze
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            maze[row][col] = 1; // set all walls
        }
    }

    // Seed random number generator
    srand(time(NULL));

    // Set random starting position
    int startRow = rand() % ROW, startCol = rand() % COL;

    // Generate maze
    generateMaze(maze, startRow, startCol);

    // Print maze
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (maze[row][col] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

void generateMaze(int maze[ROW][COL], int row, int col) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
    int randomIndex, randomRow, randomCol;
    int count = 0;

    // Check for adjacent cells that are walls
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL && maze[newRow][newCol] == 1) {
            count++;
        }
    }

    // If count is less than 2, this means we are creating a new path or we are backtracking
    if (count < 2) {
        // Set current cell as empty
        maze[row][col] = 0;

        // Shuffle directions
        for (int i = 0; i < 4; i++) {
            randomIndex = rand() % 4;
            int temp1 = directions[i][0];
            int temp2 = directions[i][1];
            directions[i][0] = directions[randomIndex][0];
            directions[i][1] = directions[randomIndex][1];
            directions[randomIndex][0] = temp1;
            directions[randomIndex][1] = temp2;
        }

        // Recurse each direction
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];

            if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL && maze[newRow][newCol] == 1) {
                if (directions[i][0] == -1) { // up
                    maze[row-1][col] = 0;
                    generateMaze(maze, row-1, col);
                } else if (directions[i][0] == 1) { // down
                    maze[row+1][col] = 0;
                    generateMaze(maze, row+1, col);
                } else if (directions[i][1] == -1) { // left
                    maze[row][col-1] = 0;
                    generateMaze(maze, row, col-1);
                } else if (directions[i][1] == 1) { // right
                    maze[row][col+1] = 0;
                    generateMaze(maze, row, col+1);
                }
            }
        }
    }
}
//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 15
#define WALL_CHAR '#'
#define SPACE_CHAR ' '

void generateMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);

int main()
{
    char maze[ROWS][COLS];

    // Set random seed for maze generation
    srand(time(NULL));

    // Generate maze
    generateMaze(maze);

    // Print maze
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[ROWS][COLS])
{
    int i, j;

    // Initialize maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL_CHAR;
        }
    }

    // Generate random start position
    int startX = rand() % ROWS;
    int startY = rand() % COLS;
    maze[startX][startY] = SPACE_CHAR;

    // Generate maze paths using recursive backtracking
    int currentX = startX, currentY = startY;
    int visitedCount = 1;   // Start with one visited cell - the start position

    while (visitedCount < ROWS * COLS) {
        // Check for unvisited neighbors
        int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int numNeighbors = 4;
        for (i = 0; i < numNeighbors; i++) {
            int neighborX = currentX + neighbors[i][0];
            int neighborY = currentY + neighbors[i][1];

            // Ignore neighbors outside the maze boundaries
            if (neighborX < 0 || neighborX >= ROWS || neighborY < 0 || neighborY >= COLS) {
                continue;
            }

            // Ignore neighbors already visited or wall cells
            if (maze[neighborX][neighborY] != WALL_CHAR) {
                numNeighbors--;
                continue;
            }

            // Carve out maze path and update current position
            maze[neighborX][neighborY] = SPACE_CHAR;
            currentX = neighborX;
            currentY = neighborY;
            visitedCount++;
            break;
        }

        // If all neighbors are visited, backtrack to last unvisited cell
        if (numNeighbors == 0) {
            for (i = ROWS - 1; i >= 0; i--) {
                for (j = COLS - 1; j >= 0; j--) {
                    if (maze[i][j] == SPACE_CHAR) {
                        currentX = i;
                        currentY = j;
                        break;
                    }
                }
                if (j >= 0) {
                    break;
                }
            }
        }
    }
}

void printMaze(char maze[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}